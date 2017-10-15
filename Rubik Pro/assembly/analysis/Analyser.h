#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>
#include <vector>

using namespace std;

const int NUM_OF_WHITES = 4; //������� � ���� ���������� ��������� ������ ������ (4 - ������� � 4 - �����)
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

	// ����� ��� �����, �� ������� ���� ����� ��������
	_edgeVector& findWhitesEdge();
	// ����� ��� ������, �� ������� ���� ����� ��������
	void findWhitesCorn(_cornVector & whitesCorn);

private:
	Cube & _cube;

	// ������ �������� ���� ������������� � ���, ������������������ �� ������ �� ������ ������
	_edgeVector _whitesEdge;
	_cornVector _whitesCorn;

	//Element* _elements[NUM_OF_ELEMENTS];

	//Corner* _whitesCorn[NUM_OF_WHITES];
	//Edge* _whitesEdge[NUM_OF_WHITES];

	Element* _yellows[NUM_OF_YELLOWS];
	Element* _sideEdges[NUM_OF_SIDE_EDGES];




	// ������ ������� - �����
	int _cornersMap[8][3][3]{ // ����� ��� ����� ����� � �����������
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
		{ { 2, 2, 1 },{ 5, 2, 1 } }, // ������� ���� 
		{ { 2, 1, 0 },{ 3, 1, 2 } },
		{ { 2, 0, 1 },{ 0, 0, 1 } },
		{ { 2, 1, 2 },{ 1, 1, 0 } },

		{ { 5, 1, 2 },{ 3, 2, 1 } }, // ������� ����
		{ { 3, 0, 1 },{ 0, 1, 2 } },
		{ { 0, 1, 0 },{ 1, 0, 1 } },
		{ { 1, 2, 1 },{ 5, 1, 0 } },

		{ { 4, 2, 1 },{ 5, 0, 1 } }, // ������ ����
		{ { 4, 1, 2 },{ 3, 1, 0 } },
		{ { 4, 0, 1 },{ 0, 2, 1 } },
		{ { 4, 1, 0 },{ 1, 1, 2 } },
	};

//	std::map<Color, Color>  sideEdgesAssoc[4] { { GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE}, {ORANGE, GREEN} };

	//������� ��������� ��� ������ �� ������� �����
	//bool cmpEdgeVectorsBySecondColor(const pair<Edge*, bool> x, const pair<Edge*, bool> y);
};