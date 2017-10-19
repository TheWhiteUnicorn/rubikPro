#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>
#include <vector>

using namespace std;

const int NUM_OF_WHITES = 4; //Имеется в виду количество элементов одного класса (4 - угловых и 4 - ребра)
const int NUM_OF_MID_EDGES = 4;
const int NUM_OF_YELLOWS = 4;


#define _edgeVector vector<Edge*>
#define _cornVector vector<Corner*>

class Analyser {
public:
	Analyser(Cube & cube);
	~Analyser();

	void set_cube(Cube& cub) { this->_cube = cub; }

	void refresh();

	// Найти все грани, на которых есть белая наклейка
	_edgeVector& findWhitesEdge();
	// Найти все уголки, на которых есть белая наклейка
	_cornVector& findWhitesCorn();
	// Найти все грани, на которых нет ни белой ни желтой наклейки
	_edgeVector& findMidEdge();

private:
	Cube & _cube;

	_edgeVector _whitesEdge;
	_cornVector _whitesCorn;
	_edgeVector _midEdges;

	Element* _yellows[NUM_OF_YELLOWS];





	// Восемь уголков - карта
	int _cornersMap[8][3][3]{ // ЗДЕСЬ ВСЕ ОЧЕНЬ ХОРОШО И ПРАВИЛЬНО :3
		{ { 2, 2, 0 },{ 5, 2, 2 },{ 3, 2, 2 } }, // Верхний слой
		{ { 2, 0, 0 },{ 3, 0, 2 },{ 0, 0, 2 } },
		{ { 2, 0, 2 },{ 0, 0, 0 },{ 1, 0, 0 } },
		{ { 2, 2, 2 },{ 1, 2, 0 },{ 5, 2, 0 } },

		{ { 4, 2, 2 },{ 3, 2, 0 },{ 5, 0, 2 } }, // Нижний слой
		{ { 4, 0, 2 },{ 0, 2, 2 },{ 3, 0, 0 } },
		{ { 4, 0, 0 },{ 1, 0, 2 },{ 0, 2, 0 } },
		{ { 4, 2, 0 },{ 5, 0, 0 },{ 1, 2, 2 } },
	};

	// 12 граней - карта
	int _edgesMap[12][2][3]{
		{ { 2, 2, 1 },{ 5, 2, 1 } }, // Верхний слой 
		{ { 2, 1, 0 },{ 3, 1, 2 } },
		{ { 2, 0, 1 },{ 0, 0, 1 } },
		{ { 2, 1, 2 },{ 1, 1, 0 } },

		{ { 5, 1, 2 },{ 3, 2, 1 } }, // Средний слой
		{ { 3, 0, 1 },{ 0, 1, 2 } },
		{ { 0, 1, 0 },{ 1, 0, 1 } },
		{ { 1, 2, 1 },{ 5, 1, 0 } },

		{ { 4, 2, 1 },{ 5, 0, 1 } }, // Нижний слой
		{ { 4, 1, 2 },{ 3, 1, 0 } },
		{ { 4, 0, 1 },{ 0, 2, 1 } },
		{ { 4, 1, 0 },{ 1, 1, 2 } },
	};

	// Карта сопоставления главного и дополнительного цвета граней среднего слоя
	map<Color, Color>  sideEdgesAssoc { { ORANGE, GREEN },{ GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE} };
};