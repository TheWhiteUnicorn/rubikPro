#pragma once
#include <vector>
#include "..\res\res.hpp"
using namespace std;
// Формулы для сборки среднего слоя (3 этап)


// Формулы для сборки нижнего креста (4 этап)
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

// Формулы для сборки нижней грани (5 этап)
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