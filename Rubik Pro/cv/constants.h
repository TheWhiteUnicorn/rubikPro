#pragma once
#include <vector>
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGTH = 480;

// Рамка области распознавания
const int FRAME_MID_X = WINDOW_WIDTH / 2;
const int FRAME_MID_Y = WINDOW_HEIGTH / 2;

const int FRAME_W = 120;
const int FRAME_H = 120;

const vector<Point> FRAME = {{ FRAME_MID_X - FRAME_W / 2, FRAME_MID_Y - FRAME_H / 2},
							 { FRAME_MID_X + FRAME_W / 2, FRAME_MID_Y + FRAME_H / 2} };

const Point SQUARES_FRAME = { FRAME_MID_X, FRAME_MID_Y };
const int SQUARES_FRAME_W = 120;
const int SQUARES_FRAME_H = 120;

const vector<vector<Point>> SQUARES_COORDS = { // Верхняя строка
   {{ SQUARES_FRAME.x - SQUARES_FRAME_W / 2, SQUARES_FRAME.y + SQUARES_FRAME_H / 2 },
	{ SQUARES_FRAME.x, SQUARES_FRAME.y + SQUARES_FRAME_H / 2 },
	{ SQUARES_FRAME.x + SQUARES_FRAME_W / 2, SQUARES_FRAME.y + SQUARES_FRAME_H / 2 } },

	// Средняя строка
	{ { SQUARES_FRAME.x - SQUARES_FRAME_W / 2, SQUARES_FRAME.y },
	{ SQUARES_FRAME.x, SQUARES_FRAME.y },
	{ SQUARES_FRAME.x + SQUARES_FRAME_W / 2, SQUARES_FRAME.y },

	// Нижняя строка
	{ { SQUARES_FRAME.x - SQUARES_FRAME_W / 2, SQUARES_FRAME.y - SQUARES_FRAME_H / 2 },
	{ SQUARES_FRAME.x, SQUARES_FRAME.y - SQUARES_FRAME_H / 2 },
	{ SQUARES_FRAME.x + SQUARES_FRAME_W / 2, SQUARES_FRAME.y - SQUARES_FRAME_H / 2 } },
}
