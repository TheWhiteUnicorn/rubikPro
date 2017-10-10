#pragma once
#include "..\res\res.hpp"
#include <deque>

using namespace std;

struct Operation {
	// Движение
	Move move;
	// Направление
	Dir direction;
};

struct Formula {
	deque<Operation> sequence;
};