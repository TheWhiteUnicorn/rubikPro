#pragma once
#include <vector>
#include "..\res\res.hpp"
using namespace std;
// ������� ��� ������ �������� ���� (3 ����)


// ������� ��� ������ ������� ������ (4 ����)
const vector<pair<Move, int>> BOT_CROSS_STICK = {
	{ F, 0 },
	{ R, 0 },
	{ U, 0 },
	{ R, 1 },
	{ U, 1 },
	{ F, 1 }
};

const vector<pair<Move, int>> BOT_CROSS_DAW = {
	{ F, 0 },
	{ U, 0 },
	{ R, 0 },
	{ U, 1 },
	{ R, 1 },
	{ F, 1 }
};

// ������� ��� ������ ������ ����� (5 ����)
const vector<pair<Move, int>> BOT_FACET_L_FISH = {
	{ R, 0 },
	{ U, 2 },
	{ R, 1 },
	{ U, 1 },
	{ R, 0 },
	{ U, 1 },
	{ R, 1 }
};

const vector<pair<Move, int>> BOT_FACET_R_FISH = {
	{ R, 0 },
	{ U, 0 },
	{ R, 1 },
	{ U, 0 },
	{ R, 0 },
	{ U, 2 },
	{ R, 1 }
};