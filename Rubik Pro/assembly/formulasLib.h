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

// ������� ��� ������ ����� ������ ����� (6 ����)
const vector<pair<Move, int>> BOT_CORNS_CYCLIC_SHIFT_ACKW = { //�������� �� ������� (���� �������� �� ������ �����)
	{ R, 2 },
	{ D, 2 },
	{ R, 0 },
	{ U, 0 },
	{ R, 1 },
	{ D, 2 },
	{ R, 0 },
	{ U, 1 },
	{ R, 0 },
};

const vector<pair<Move, int>> BOT_CORNS_CYCLIC_SHIFT_CKW = { //�������� ������ ������� (���� �������� �� ������ �����)
	{ R, 1 },
	{ U, 0 },
	{ R, 1 },
	{ D, 2 },
	{ R, 0 },
	{ U, 1 },
	{ R, 1 },
	{ D, 2 },
	{ R, 2 },
};

const vector<pair<Move, int>> BOT_CORNS_DIAGONAL_SWITCH = {
	{ F, 0 },
	{ R, 0 },
	{ U, 1 },
	{ R, 1 },
	{ U, 1 },
	{ R, 0 },
	{ U, 0 },
	{ R, 1 },
	{ F, 1 },
	{ R, 0 },
	{ U, 0 },
	{ R, 1 },
	{ U, 1 },
	{ R, 1 },
	{ F, 0 },
	{ R, 0 },
	{ F, 1 }
};