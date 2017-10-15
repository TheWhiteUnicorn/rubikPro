#pragma once
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

class InitialRecogniser
{

public:
	InitialRecogniser();
	~InitialRecogniser();

	static double angle(Point pt1, Point pt2, Point pt0);
	RubickColors * drawSquares(Mat & image, const vector<vector<Point>>& squares, int edgeShown);
	static void findSquares(const Mat & image, vector<vector<Point>>& squares);
};

