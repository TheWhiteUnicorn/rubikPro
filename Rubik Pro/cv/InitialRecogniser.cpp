#include "InitialRecogniser.h"

InitialRecogniser::InitialRecogniser (){
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
	gridRecognition(frame);

	rectangle(frame, Point(box.x, box.y), Point(box.x + box.width, box.y + box.height), Scalar(255, 0, 0), 1);
	drawBoundingSquares(frame);

	imshow("Rubic Detection", frame);
	imshow("Rubic Borders ", temp_frame);
}


int InitialRecogniser::ready()
{
	// открывает камеру по умолчанию
	cap = new VideoCapture(0); 

	if (!cap->isOpened())
	{
		return -1;
	}

	return 0;
}