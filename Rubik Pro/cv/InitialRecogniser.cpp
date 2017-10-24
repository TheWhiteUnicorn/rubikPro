#include "InitialRecogniser.h"

// ��� ������, ������� ����� ��������� � ������ �������
RubickColors rawColors;

InitialRecogniser::InitialRecogniser (){
};

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
		
		int j = 2, k = 2;

		if (squares.size() != 9) continue;
		for (size_t i = 0; i < squares.size(); i++)
		{
			const Point* p = &squares[i][0];
			int n = (int)squares[i].size();
			int shift = 1;

			// �������������� ��������������
			Rect r = boundingRect(Mat(squares[i]));  
			r.x = r.x + r.width / 4;
			r.y = r.y + r.height / 4;
			r.width = r.width / 2;
			r.height = r.height / 2;

			Mat roi = image(r);
			
			Scalar temp_color = mean(roi);
				
			color->colors[edgeShown][j][k] = temp_color;
			

			polylines(image, &p, &n, 1, true, temp_color, 2, LINE_AA, shift);

			Point center(r.x + r.width / 2, r.y + r.height / 2);

			ellipse(image, center, Size(r.width / 2, r.height / 2), 0, 0, 360, temp_color, 2, LINE_AA);

			k--;
			if (k == -1)
			{
				k = 2;
				j--;
			}
		
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

		rectangle(image, Point(500), Point(-500), Scalar(0, 255, 0), 2);
	}
};


//void draw_box(Mat & image)
//{
//	rectangle(image, Point(box.x, box.y), Point(box.x + box.width, box.y + box.height),	Scalar(0, 0, 255), 2);
//	Rect rect2 = Rect(box.x, box.y, box.width, box.height);
//}

void InitialRecogniser::showFrame()
{
	Mat frame;
	vector<vector<Point> > squares;

	*cap >> frame;

	Mat temp_frame;
	frame.copyTo(temp_frame);

	findSquares(temp_frame, squares);
	drawSquares(frame, squares);

	rectangle(frame, Point(box.x, box.y), Point(box.x + box.width, box.y + box.height), Scalar(0, 0, 255), 2);

	imshow("Rubic Detection", frame);
	imshow("Rubic Huection", temp_frame);
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