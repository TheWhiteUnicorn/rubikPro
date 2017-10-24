#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "..\res\res.hpp"

using namespace cv;
using namespace std;

struct RubickColors
{
	Scalar colors[6][3][3];
};

// ����� ������� �������������
const int FRAME_X = 260;
const int FRAME_Y = 180;
const int FRAME_W = 120;
const int FRAME_H = 120;

const vector<Point> frame = { { FRAME_X, FRAME_Y },{ FRAME_X + FRAME_W, FRAME_Y + FRAME_H }};
const Rect box = boundingRect(frame);

// ����� ���������� �������������
class InitialRecogniser
{
	VideoCapture *cap;

	// ��� ������, ������� ����� ��������� � ������ �������
	RubickColors rawColors;

	// ������ �������� ��������� �������� ������� �����
	Scalar referenceColors[6];

	// ��������������� �������
	void preprocessing(Mat &image);
	double angle(Point pt1, Point pt2, Point pt0);
	Color classifyColor(Scalar rawColor);
	//void properSquaresArrangement();

public:
	// �-���
	InitialRecogniser();

	// ������� ���������� � ������, �������� ������
	int ready();

	// ����� 9 ������� �� �����������
	void findSquares(Mat & image, vector<vector<Point>>& squares);

	// ���������� ����������, ��������������� ��������� � �����������
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);

	// ��������� ������ ������ rawColors ��� ������������ �����
	void fillSquares(int edgeShow);

	// ��������� ������������� �������������� � ���������� ���� ������ ������ ������
	void initialModelFilling(Color*** res);

	// ������������� �������������� ������ ��� �������� �����
	void semanticTransformationOfColors(Color** res, int facet);

	// �������� ����
	void showFrame();
	void nineRect(Mat &image);
};