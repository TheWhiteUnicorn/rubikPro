#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "..\res\res.hpp"
#include "constants.h"
#include "..\cube\Cube.h"

using namespace cv;
using namespace std;

struct RubickColors
{
	Scalar colors[6][3][3];
};

const Rect box = boundingRect(FRAME);

// ����� ���������� �������������
class InitialRecogniser
{
	VideoCapture *cap;

	// ������� - ����� ������, ������������ �� ��������� �����
	Scalar curFacetBuffer[3][3];
	// ��� ������, ������� ����� ��������� � ������ �������
	RubickColors rawColors;

	// ������ �������� ��������� �������� ������� �����
	Scalar referenceColors[6];

	// ��������������� �������
	void preprocessing(Mat & image);
	double angle(Point pt1, Point pt2, Point pt0);
	Color classifyColor(Scalar rawColor);
	//void properSquaresArrangement();
	void drawBoundingSquares(Mat & image);

	// ����� 9 ������� �� �����������
	void findSquares(Mat & image, vector<vector<Point>>& squares);

	// ���������� ����������, ��������������� ��������� � �����������
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);

	 // ���������� ���������� �� �������
	void gridRecognition(Mat& image);

public:
	// �-���
	InitialRecogniser();

	// ������� ���������� � ������, �������� ������
	int ready();

	// ���������� ����� ������ � ������ rawColors
	void saveEdgeColorsBuffer(int edge);

	// ��������� ������ ������ rawColors ��� ������������ �����
	void fillSquares(int edgeShow);

	// ��������� ������������� �������������� � ���������� ���� ������ ������ ������
	void initialModelFilling(CubeColorsTable& res);

	// ������������� �������������� ������ ��� �������� �����
	void semanticTransformationOfColors(FacetColorsMatrix& res, int facet);

	// �������� ����
	void showFrame();
};