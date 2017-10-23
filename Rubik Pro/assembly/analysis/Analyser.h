#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>
#include <vector>

using namespace std;

const int NUM_OF_WHITES = 4; //������� � ���� ���������� ��������� ������ ������ (4 - ������� � 4 - �����)
const int NUM_OF_MID_EDGES = 4;
const int NUM_OF_YELLOWS = 4;


#define _edgeVector vector<Edge*>
#define _cornVector vector<Corner*>

// ��������, ������� ����� ��������� �� ������ ������ (�����, �����, �����, �����)
enum YellowCrossSituation { STICK, DAW, DOT, CROSS };

// ��������, ������� ����� ��������� �� ������ ���� (����� �����, ������ �����, �����, ���, ���������, ������� �����, ��������, ������� �������)
enum YellowLayerSituation {L_FISH, R_FISH, EYES, EARS, EIGHT, D_EYES, HELI, LAYER_DONE};

// ��������, ������� ����� ��������� c ��������� ������� ����
enum BotCornsSituation { BOT_C_CYCLIC_SHIFT_CKW, BOT_C_CYCLIC_SHIFT_ACKW, BOT_C_DIAGONAL_SWITCH, BOT_C_DONE };

// ��������, ������� ����� ��������� c ������� ������� ���� ()
enum BotEdgesSituation {BOT_E_SHIFT_CKW, BOT_E_SHIFT_ACKW, BOT_E_SLAIGH, BOT_E_CROSS, BOT_E_DONE};

class Analyser {
public:
	Analyser(Cube & cube);
	~Analyser();

	void set_cube(Cube& cub) { this->_cube = cub; }

	void refresh();

	// ����� ��� �����, �� ������� ���� ����� ��������
	_edgeVector& findWhitesEdge();
	// ����� ��� ������, �� ������� ���� ����� ��������
	_cornVector& findWhitesCorn();
	// ����� ��� �����, �� ������� ��� �� ����� �� ������ ��������
	_edgeVector& findMidEdge();
	// ������� ��������, ������� ����� ��������� �� ������ ������ (�����, �����, �����, �����). ��������������, ��� ������ ����� ����������� ������
	YellowCrossSituation findYellowCrossSituations(Dir&);
	// ������� ��������, ������� ����� ��������� �� ������ ���� (��. ���������� ������������). ��������������, ��� ������ ����� ����������� ������
	YellowLayerSituation findYellowLayerSituations(Dir&);
	// ���������� ������������ ������ ������� ���������
	// ����� �������� ���������� ����, ������� ������ ���� ������ ��� ������������
	BotCornsSituation findBotCornsConfig(Color&);
	// ������� ��������, ������� ����� ��������� c ������� ������� ����
	BotEdgesSituation findBotEdgesSituation(Dir& res);

private:
	Cube & _cube;

	_edgeVector _whitesEdge;
	_cornVector _whitesCorn;
	_edgeVector _midEdges;



	// ++++++++++ ��������������� ���������� ++++++++++++++++

	// ������ ������� - �����
	int _cornersMap[8][3][3]{ // ����� ��� ����� ������ � ��������� :3
		{ { 2, 2, 0 },{ 5, 2, 2 },{ 3, 2, 2 } }, // ������� ����
		{ { 2, 0, 0 },{ 3, 0, 2 },{ 0, 0, 2 } },
		{ { 2, 0, 2 },{ 0, 0, 0 },{ 1, 0, 0 } },
		{ { 2, 2, 2 },{ 1, 2, 0 },{ 5, 2, 0 } },

		{ { 4, 2, 2 },{ 3, 2, 0 },{ 5, 0, 2 } }, // ������ ����
		{ { 4, 0, 2 },{ 0, 2, 2 },{ 3, 0, 0 } },
		{ { 4, 0, 0 },{ 1, 0, 2 },{ 0, 2, 0 } },
		{ { 4, 2, 0 },{ 5, 0, 0 },{ 1, 2, 2 } },
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

	// ����� ������������� �������� � ��������������� ����� ������ �������� ����
	map<Color, Color>  sideEdgesAssoc { { ORANGE, GREEN },{ GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE} };
};