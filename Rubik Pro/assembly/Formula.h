#pragma once
#include "..\res\res.hpp"
#include <deque>

using namespace std;

struct Operation {
	// ��������
	Move move;
	// �����������
	Dir direction;
};

struct Formula {
	deque<Operation> sequence;
};