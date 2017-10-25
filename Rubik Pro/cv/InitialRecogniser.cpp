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

	rectangle(frame, Point(box.x, box.y), Point(box.x + box.width, box.y + box.height), Scalar(0, 0, 255), 2);
	drawBoundingSquares(frame);

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