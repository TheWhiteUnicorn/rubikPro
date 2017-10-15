#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>
#include <vector>

using namespace std;

const int NUM_OF_WHITES = 4; //Имеется в виду количество элементов одного класса (4 - угловых и 4 - ребра)
const int NUM_OF_YELLOWS = 4;
const int NUM_OF_SIDE_EDGES = 4;

#define _edgeVector vector<pair<Edge*, bool>>
#define _cornVector vector<pair<Corner*, bool>>

class Analyser {
public:
	Analyser(Cube & cube);
	~Analyser();

	void set_cube(Cube& cub) { this->_cube = cub; }

	void refresh();

	// Найти все грани, на которых есть белая наклейка
	_edgeVector& findWhitesEdge();
	// Найти все уголки, на которых есть белая наклейка
	void findWhitesCorn(_cornVector & whitesCorn);

private:
	Cube & _cube;

	// Второе значение пары сигнализирует о том, проинициализирован ли объект на данный момент
	_edgeVector _whitesEdge;
	_cornVector _whitesCorn;

	//Element* _elements[NUM_OF_ELEMENTS];

	//Corner* _whitesCorn[NUM_OF_WHITES];
	//Edge* _whitesEdge[NUM_OF_WHITES];

	Element* _yellows[NUM_OF_YELLOWS];
	Element* _sideEdges[NUM_OF_SIDE_EDGES];




	// Восемь уголков - карта
	int _cornersMap[8][3][3]{ // ЗДЕСЬ ВСЕ ОЧЕНЬ ПЛОХО И НЕПРАВИЛЬНО
		{ { 0, 0, 2 },{ 2, 0, 0 },{ 3, 0, 2 } }, // Верхний слой
		{ { 0, 2, 2 },{ 3, 0, 0 },{ 4, 0, 2 } },
		{ { 0, 2, 0 },{ 4, 0, 0 },{ 1, 0, 2 } },
		{ { 0, 0, 0 },{ 1, 0, 0 },{ 2, 0, 2 } },

		{ { 5, 2, 2 },{ 3, 2, 2 },{ 2, 2, 0 } }, // Нижний слой
		{ { 5, 0, 2 },{ 4, 2, 2 },{ 3, 2, 0 } },
		{ { 5, 0, 0 },{ 1, 2, 2 },{ 4, 2, 0 } },
		{ { 5, 2, 0 },{ 2, 2, 2 },{ 1, 2, 0 } },
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

//	std::map<Color, Color>  sideEdgesAssoc[4] { { GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE}, {ORANGE, GREEN} };

	//Функция сравнения двх граней по второму цвету
	//bool cmpEdgeVectorsBySecondColor(const pair<Edge*, bool> x, const pair<Edge*, bool> y);
};