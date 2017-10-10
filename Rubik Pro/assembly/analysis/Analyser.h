#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>

const int NUM_OF_ELEMENTS = 27;
const int NUM_OF_WHITES = 4;
const int NUM_OF_YELLOWS = 9;
const int NUM_OF_SIDE_EDGES = 4;


class Analyser {
public:
	Analyser(Cube & cube);
	~Analyser();

	// ����� ��� �����, �� ������� ���� ����� ��������
	const Edge ** Analyser::findWhitesEdge();
	// ����� ��� ������, �� ������� ���� ����� ��������
	const Element** findWhitesCorn();

private:
	Cube & _cube;

	Element* _elements[NUM_OF_ELEMENTS];

	Corner* _whitesCorn[NUM_OF_WHITES];
	Edge* _whitesEdge[NUM_OF_WHITES];

	Element* _yellows[NUM_OF_YELLOWS];
	Element* _sideEdges[NUM_OF_SIDE_EDGES];




	// ������ ������� - �����
	int _cornersMap[8][3][3]{
		{ { 0, 0, 2 },{ 2, 0, 0 },{ 3, 0, 2 } }, // ������� ����
		{ { 0, 2, 2 },{ 3, 0, 0 },{ 4, 0, 2 } },
		{ { 0, 2, 0 },{ 4, 0, 0 },{ 1, 0, 2 } },
		{ { 0, 0, 0 },{ 1, 0, 0 },{ 2, 0, 2 } },

		{ { 5, 2, 2 },{ 3, 2, 2 },{ 2, 2, 0 } }, // ������ ����
		{ { 5, 0, 2 },{ 4, 2, 2 },{ 3, 2, 0 } },
		{ { 5, 0, 0 },{ 1, 2, 2 },{ 4, 2, 0 } },
		{ { 5, 2, 0 },{ 2, 2, 2 },{ 1, 2, 0 } },
	};

	// 12 ������ - �����
	int _edgesMap[12][2][3]{
		{ { 0, 0, 1 },{ 2, 0, 1 } }, // ������� ���� 
		{ { 0, 1, 2 },{ 3, 0, 1 } },
		{ { 0, 2, 1 },{ 4, 0, 1 } },
		{ { 0, 1, 0 },{ 1, 0, 1 } },

		{ { 2, 1, 0 },{ 3, 1, 2 } }, // ������� ����
		{ { 3, 1, 0 },{ 4, 1, 2 } },
		{ { 4, 1, 0 },{ 1, 1, 2 } },
		{ { 1, 1, 0 },{ 2, 1, 2 } },

		{ { 5, 2, 1 },{ 2, 2, 1 } }, // ������ ����
		{ { 5, 1, 2 },{ 3, 2, 1 } },
		{ { 5, 0, 1 },{ 4, 2, 1 } },
		{ { 5, 1, 0 },{ 1, 2, 1 } },
	};

//	std::map<Color, Color>  sideEdgesAssoc[4] { { GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE}, {ORANGE, GREEN} };
};