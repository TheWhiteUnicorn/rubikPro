#include "InitialRecogniser.h"

InitialRecogniser::InitialRecogniser (){
};


void InitialRecogniser::drawSquares(Mat & image, const vector<vector<Point>>& squares)
{
	for (size_t i = 0; i < squares.size(); i++)
	{
		const Point* p = &squares[i][0];
		int n = (int)squares[i].size();
		int shift = 1;

		Rect r = boundingRect(Mat(squares[i])); // Ограничивающие прямоугольники 

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


void InitialRecogniser::gridRecognition(Mat & image)
{
	
};



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
	//imshow("Rubic Huection", temp_frame);
}


int InitialRecogniser::ready()
{
	cap = new VideoCapture(0); // opens default webcam

	if (!cap->isOpened())
	{
		return -1;
	}

	return 0;
}