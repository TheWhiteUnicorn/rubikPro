#include "..\InitialRecogniser.h"

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

void InitialRecogniser::preprocessing(Mat &image) {
	Mat element = getStructuringElement(0, Size(3, 3), Point(1));
	cvtColor(image, image, COLOR_BGR2GRAY);
	Canny(image, image, 55, 70);
	morphologyEx(image, image, MORPH_GRADIENT, element);
	morphologyEx(image, image, MORPH_CLOSE, element);
};


// ���������� ������������������ ���������, ������������ �� �����������.
// ������������������ ����������� � ��������� ���������
void InitialRecogniser::findSquares(Mat& image, vector<vector<Point> >& squares) {
	squares.clear();

	vector<vector<Point> > contours;

	preprocessing(image);

	// ���������� �������������� �������
	Mat roiImage = image(box);

	// ����� ������� � ��������� �� ��� ��� ������
	findContours(roiImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

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


void InitialRecogniser::drawSquares(Mat & image, const vector<vector<Point>>& squares) {
	for (size_t i = 0; i < squares.size(); i++)
	{
		const Point* p = &squares[i][0];
		int n = (int)squares[i].size();
		int shift = 1;

		Rect r = boundingRect(Mat(squares[i])); // �������������� �������������� 

		r.x = r.x + r.width / 4;
		r.y = r.y + r.height / 4;
		r.width = r.width / 2;
		r.height = r.height / 2;

		Mat roiImage = image(box);

		Mat roi = roiImage(r);
		Scalar temp_color = mean(roi);

		//polylines(image, &p, &n, 1, true, temp_color, 2, LINE_AA, shift);
		fillPoly(image, &p, &n, 1, temp_color, LINE_AA, shift);

		Point center(r.x + r.width / 2, r.y + r.height / 2);
		ellipse(roiImage, center, Size(r.width / 2, r.height / 2), 0, 0, 360, temp_color, 2, LINE_AA);

	}
};