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

// Класс начального распознавания
class InitialRecogniser
{
	VideoCapture *cap;

	// Матрица - буфер цветов, распознанных на последнем кадре
	Scalar curFacetBuffer[3][3];
	// Это массив, который нужно заполнять с каждым вызовом
	RubickColors rawColors;

	// Массив скаляров эталонных значений каждого цвета
	Scalar referenceColors[6];

	// Вспомогательные функции
	void preprocessing(Mat & image);
	double angle(Point pt1, Point pt2, Point pt0);
	Color classifyColor(Scalar rawColor);
	//void properSquaresArrangement();
	void drawBoundingSquares(Mat & image);

	// Найти 9 наклеек на изображении
	void findSquares(Mat & image, vector<vector<Point>>& squares);

	// Отрисовать квадратики, соответствующие наклейкам в изображении
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);

	 // Распознать квадратики по шаблону
	void gridRecognition(Mat& image);

public:
	// К-тор
	InitialRecogniser();

	// Функция подготовки к работе, открывет камеру
	int ready();

	// Отпечатать буфер цветов в массив rawColors
	void saveEdgeColorsBuffer(int edge);

	// Заполнить массив цветов rawColors для определенной грани
	void fillSquares(int edgeShow);

	// Начальное семантическое преобразование и заполнение всех граней модели кубика
	void initialModelFilling(CubeColorsTable& res);

	// Семантическое преобразование цветов для заданной грани
	void semanticTransformationOfColors(FacetColorsMatrix& res, int facet);

	// Показать кадр
	void showFrame();
};