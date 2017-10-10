#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

// ��������������� �������:
// ������� ������� ���� ����� ���������
// �� pt0-> pt1 � �� pt0-> pt2
static double angle(Point pt1, Point pt2, Point pt0)
{
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	double cos = (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
	return cos;
}

static void drawSquares(Mat& image, const vector<vector<Point> >& squares) 
{
	for (size_t i = 0; i < squares.size(); i++)
	{
		const Point* p = &squares[i][0];
		int n = (int)squares[i].size();
		int shift = 1;

		Rect r = boundingRect(Mat(squares[i])); // �������������� �������������� 
		r.x = r.x + r.width / 16;
		r.y = r.y + r.height / 16;
		r.width = r.width / 2;
		r.height = r.height / 2;

		Mat roi = image(r);
		Scalar color = mean(roi);
		polylines(image, &p, &n, 1, true, color, 2, LINE_AA, shift);

		Point center(r.x + r.width / 2, r.y + r.height / 2);
		ellipse(image, center, Size(r.width / 2, r.height / 2), 0, 0, 360, color, 2, LINE_AA);
	}
}

// ���������� ������������������ ���������, ������������ �� �����������.
// ������������������ ����������� � ��������� ���������
static void findSquares(const Mat& image, vector<vector<Point> >& squares)
{
	squares.clear();

	Mat gray, gray0;

	vector<vector<Point> > contours;

	cvtColor(image, gray0, COLOR_BGR2GRAY);
	GaussianBlur(image, gray0, Size(7, 7), 1.5, 1.5);
	dilate(image, image, NULL);
	Canny(gray0, gray, 50, 200, 3);
	GaussianBlur(gray, gray0, Size(7, 7), 1.5, 1.5);



	// ����� ������� � ��������� �� ��� ��� ������
	findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	vector<Point> approx;

	// ��������� ������ ������
	for (size_t i = 0; i < contours.size(); i++)
	{
		// ��������������� ������ � ������� �����������
		// � ��������� �������
		approxPolyDP(Mat(contours[i]), approx, 9, true);

		// ���������� ������� ������ ����� 4 ������� ����� �������������
		// ������������ ������� ������� (����� ������������� ������ �������)
		// � ���� ���������.
		// ����������: ���������� �������� ������� ������������, ������ ���
		// ������� ����� ���� ������������� ��� ������������� - � ������������ �
		// ����������� ��������.
		if (approx.size() == 4 &&
			fabs(contourArea(Mat(approx))) > 5 &&
			isContourConvex(Mat(approx)))
		{
			double maxCosine = 0;

			for (int j = 2; j < 5; j++)
			{
				// ����� ������������ ������� ���� ����� ��������� �������.
				double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
				maxCosine = MAX(maxCosine, cosine);
			}

			// ���� �������� ���� ����� ����
			// (��� ���� ~ 90 ��������) ����� ��������� ��������������� 
			// ������� � �������������� ������������������

			if (maxCosine < 0.3)
				squares.push_back(approx);
		}
	}
}


int Camera()
{

	VideoCapture cap(0); // opens default webcam

	if (!cap.isOpened())
	{
		return -1;
	}

	Mat frame;
	vector<vector<Point> > squares;

	for (;;)
	{
		cap >> frame;

		if (frame.empty())
		{
			return -1;
		}
		findSquares(frame, squares);
		drawSquares(frame, squares);
		imshow("Rubic Detection", frame);

		char c = cvWaitKey(33);
		if (c == 27)  // ������ ESC

			break;
	}
}