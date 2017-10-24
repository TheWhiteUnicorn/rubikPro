#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

struct RubickColors
{
	Scalar colors[6][3][3];
};

// Рамка области распознавания
const vector<Point> frame = { { 100, 100 },{ 100, 400 },{ 400, 100 },{ 400, 400 } };
const Rect box = boundingRect(frame);


class InitialRecogniser
{
	VideoCapture *cap;
	void preprocessing(Mat &image);

public:

	InitialRecogniser();

	int CubeCV();
	double angle(Point pt1, Point pt2, Point pt0);
	RubickColors * fillSquares(int edgeShow);
	void findSquares(Mat & image, vector<vector<Point>>& squares);
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);
	void showFrame();
};