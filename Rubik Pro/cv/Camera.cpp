#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int Test()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	namedWindow("edges", 1);
	int counter = 0;
	char filename[512];

	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera

		cvtColor(frame, edges, CV_BGR2GRAY); //CV_BGR2GRA

											 // apply your filter

											 //GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
											 //erode(edges, edges, NULL);
											 //dilate(edges, edges, NULL);
											 //Canny(edges, edges, 0, 30, 3);
		IplImage* color_dst = 0;


		adaptiveThreshold(edges, edges, 250, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 15, 3);

		// хранилище памяти для хранения найденных линий
		CvMemStorage* storage = cvCreateMemStorage(0);
		CvSeq* lines = 0;
		int i = 0;

		IplImage image;
		image = IplImage(edges);

		// нахождение линий
		//	lines = cvHoughLines2(&image, storage, CV_HOUGH_STANDARD, 1, CV_PI / 180, 50, 50, 10);

		// нарисуем найденные линии
		//for (i = 0; i < lines->total; i++) {
		//CvPoint* line = (CvPoint*)cvGetSeqElem(lines, i);
		//cvLine(color_dst, line[0], line[1], CV_RGB(255, 0, 0), 3, CV_AA, 0);
		//}


		cvNamedWindow("Hough", 1);
		cvShowImage("Hough", color_dst);

		// find the contours
		vector< vector<Point> > contours;
		CvSeq* contour = 0;
		CvSeq* contourLow = 0;
		findContours(edges, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

		Mat mask = Mat::zeros(edges.rows, edges.cols, CV_8UC1);




		// CV_FILLED fills the connected components found
		//drawContours(mask, contours, -1, Scalar(255), CV_FILLED);

		int counter = 0;
		char filename[512];
		imshow("edges", edges);
		char c = cvWaitKey(33);
		if (c == 27) { // нажата ESC
			break;
		}
		else if (c == 13) { // Enter
							// сохраняем кадр в файл
			IplImage image;
			image = IplImage(frame);
			sprintf_s(filename, "Image%d.jpg", counter);
			printf("[i] capture... %s\n", filename);
			cvSaveImage(filename, &image);
			counter++;
		}

	}

	return 0;
}