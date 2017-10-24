#pragma once
#include <vector>
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGTH = 480;

// ����� ������� �������������
const int FRAME_MID_X = WINDOW_WIDTH / 2;
const int FRAME_MID_Y = WINDOW_HEIGTH / 2;

const int FRAME_W = 120;
const int FRAME_H = 120;

const vector<Point> frame = {{ FRAME_MID_X - FRAME_W / 2, FRAME_MID_Y - FRAME_H / 2},
							 { FRAME_MID_X + FRAME_W / 2, FRAME_MID_Y + FRAME_H / 2} };

