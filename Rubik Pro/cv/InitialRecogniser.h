#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "..\res\res.hpp"
#include "constants.h"

using namespace cv;
using namespace std;

struct RubickColors
{
	Scalar colors[6][3][3];
};

const Rect box = boundingRect(frame);

//const vector<Point> 

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
	void gridRecognition(Mat &image);
};