#include "InitialRecogniser.h"

// ��� ������, ������� ����� ��������� � ������ �������
RubickColors rawColors;

InitialRecogniser::InitialRecogniser (){
	
};

// ��������������� �������:
// ������� ������� ���� ����� ���������
// �� pt0-> pt1 � �� pt0-> pt2
double InitialRecogniser::angle(Point pt1, Point pt2, Point pt0) {
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	double cos = (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
	return cos;
}



RubickColors * InitialRecogniser::fillSquares(int edgeShown /* ��� ����� �����, ������� ����������, ������� ��� �������, ���� ������� � �����. ������ � ����� ����������*/) {
	RubickColors *color = new RubickColors();

	Mat image;
	vector<vector<Point> > squares;

	while (squares.size() != 9) {

		*cap >> image;

		Mat temp_frame;
		image.copyTo(temp_frame);
		findSquares(temp_frame, squares);
		drawSquares(image, squares);
		imshow("Rubic roi", image);
		

		if (squares.size() != 9) continue;
		for (size_t i = 0; i < squares.size(); i++)
		{
			const Point* p = &squares[i][0];
			int n = (int)squares[i].size();
			int shift = 1;

			// �������������� ��������������
			Rect r = boundingRect(Mat(squares[i]));  
			r.x = r.x + r.width / 16;
			r.y = r.y + r.height / 16;
			r.width = r.width / 2;
			r.height = r.height / 2;

			Mat roi = image(r);
			
			Scalar temp_color = mean(roi);

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					color->colors[edgeShown][i][j] = temp_color;
				}
			}


			polylines(image, &p, &n, 1, true, temp_color, 2, LINE_AA, shift);

			Point center(r.x + r.width / 2, r.y + r.height / 2);
			ellipse(image, center, Size(r.width / 2, r.height / 2), 0, 0, 360, temp_color, 2, LINE_AA);

		}
		
	}
	return color;
}


void InitialRecogniser::drawSquares(Mat & image, const vector<vector<Point>>& squares)
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
		
		Scalar temp_color = mean(roi);

		polylines(image, &p, &n, 1, true, temp_color, 2, LINE_AA, shift);

		Point center(r.x + r.width / 2, r.y + r.height / 2);
		ellipse(image, center, Size(r.width / 2, r.height / 2), 0, 0, 360, temp_color, 2, LINE_AA);
	}
};

void InitialRecogniser::preprocessing(Mat &image)
{
	Mat element = getStructuringElement(0, Size(3, 3), Point(1));
	cvtColor(image, image, COLOR_BGR2GRAY);
	Canny(image, image, 55, 70);
	morphologyEx(image, image, MORPH_GRADIENT, element);
	morphologyEx(image, image, MORPH_CLOSE, element);
};


// ���������� ������������������ ���������, ������������ �� �����������.
// ������������������ ����������� � ��������� ���������
void InitialRecogniser::findSquares( Mat& image, vector<vector<Point> >& squares) {
	squares.clear();

	vector<vector<Point> > contours;

	preprocessing(image);

	// ����� ������� � ��������� �� ��� ��� ������
	findContours(image, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

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

void InitialRecogniser::showFrame()
{
	Mat frame;
	vector<vector<Point> > squares;

	*cap >> frame;

	//if (frame.empty())
	//{
	//	return -1;
	//}
	Mat temp_frame;
	frame.copyTo(temp_frame);

	findSquares(temp_frame, squares);
	drawSquares(frame, squares);

	imshow("Rubic Detection", frame);
	//imshow("Rubic Huection", temp_frame);
	
}

int InitialRecogniser::CubeCV()
{
	cap = new VideoCapture(0); // opens default webcam

	if (!cap->isOpened())
	{
		return -1;
	}

	return 0;
}