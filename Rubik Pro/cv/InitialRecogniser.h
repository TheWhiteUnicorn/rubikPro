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

// Класс начального распознавания
class InitialRecogniser
{
	VideoCapture *cap;

	// Это массив, который нужно заполнять с каждым вызовом
	RubickColors rawColors;

	// Массив скаляров эталонных значений каждого цвета
	Scalar referenceColors[6];

	// Вспомогательные функции
	void preprocessing(Mat &image);
	double angle(Point pt1, Point pt2, Point pt0);
	Color classifyColor(Scalar rawColor);
	//void properSquaresArrangement();

public:
	// К-тор
	InitialRecogniser();

	// Функция подготовки к работе, открывет камеру
	int ready();

	// Найти 9 наклеек на изображении
	void findSquares(Mat & image, vector<vector<Point>>& squares);

	// Отрисовать квадратики, соответствующие наклейкам в изображении
	void drawSquares(Mat & image, const vector<vector<Point>>& squares);

	// Заполнить массив цветов rawColors для определенной грани
	void fillSquares(int edgeShow);

	// Начальное семантическое преобразование и заполнение всех граней модели кубика
	void initialModelFilling(Color*** res);

	// Семантическое преобразование цветов для заданной грани
	void semanticTransformationOfColors(Color** res, int facet);

	// Показать кадр
	void showFrame();
	void gridRecognition(Mat &image);
};