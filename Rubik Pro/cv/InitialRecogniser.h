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
const int FRAME_X = 260;
const int FRAME_Y = 180;
const int FRAME_W = 120;
const int FRAME_H = 120;

const vector<Point> frame = { { FRAME_X, FRAME_Y },{ FRAME_X + FRAME_W, FRAME_Y + FRAME_H }};
const Rect box = boundingRect(frame);

//const vector<Point> frame = { {387, 153}, {387, 220}, {387, 287}, {320, 153}, {320, 220}, {320, 287}, {253, 153}, {253, 220}, {253, 287} };
//const Rect pt = boundingRect(frame);

class InitialRecogniser
{
	VideoCapture *cap;

	// Это массив, который нужно заполнять с каждым вызовом
	RubickColors rawColors;

	// Вспомогательные функции
	void preprocessing(Mat &image);
	double angle(Point pt1, Point pt2, Point pt0);
public:
	// К-тор
	InitialRecogniser();

	// Функция подготовки к работе, открывет камеру
	int ready();


	RubickColors * fillSquares(int edgeShow);
	void findSquares(Mat & image, vector<vector<Point>>& squares);
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);
	void showFrame();
	void nineRect(Mat &image);
};