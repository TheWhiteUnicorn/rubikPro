#include "Recognition.h"
#include "../res/res.hpp"




int CubeCV()
{

	

	for (;;)
	{
		if (!cap.isOpened())
		{
			VideoCapture cap(0);
		}

		cap >> frame;

		if (frame.empty())
		{
			return -1;
		}
		findSquares(frame, squares);
		drawSquares(frame, squares);
		//Array(frame, squares);
		imshow("Rubic Detection", frame);

		char c = cvWaitKey(33);
		if (c == 27)  // нажата ESC

			break;
	}
}