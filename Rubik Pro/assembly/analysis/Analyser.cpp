#include "Analyser.h"

Analyser::Analyser(Cube & cube) : _cube(cube) {}

Analyser::~Analyser() {
	for (int i = 0; i < NUM_OF_WHITES; i++) {
		delete _whitesCorn[i];
		delete _whitesEdge[i];
	}
	for (int i = 0; i < NUM_OF_YELLOWS; i++) {
		delete _yellows[i];
	}
	for (int i = 0; i < NUM_OF_SIDE_EDGES; i++) {
		delete _sideEdges[i];
	}
	for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
		delete _elements[i];
	}
}

const Edge ** Analyser::findWhitesEdge() {
	int addedEdges = 0;
	for (int i = 0, side = 0, layer = 0; i < 12; i++, side++) {
		if (side == 4) {
			side = 0;
			layer++;
		}

		Color first = _cube.get_edges()[_edgesMap[i][0][0]][_edgesMap[i][0][1]][_edgesMap[i][0][2]];
		Color second = _cube.get_edges()[_edgesMap[i][1][0]][_edgesMap[i][1][1]][_edgesMap[i][1][2]];
		if (first == WHITE) {
			_whitesEdge[addedEdges] = new Edge(ElementLocLayer(layer), side, first, second, 0);
			addedEdges++;
		}
		else if (second == WHITE) {
			_whitesEdge[addedEdges] = new Edge(ElementLocLayer(layer), side, first, second, 1);
			addedEdges++;
		}
	}

	// ���� ����� ������ 4 �����, �� ���-�� ��������, ���� ������������ ������ ��� ��� ������������ �����
	if (addedEdges < NUM_OF_WHITES) return nullptr;

	return (const Edge **)_whitesEdge;
}

const Element ** Analyser::findWhitesCorn() { // ������� �������� ������� ���� ����� ��� primary
	int addedCorners = 0;
	// +++++++++++++++ ���� ����� ������ +++++++++++++++++
	for (int i = 0, side = 0, layer = 0; i < 8; i++, side++) {
		if (side == 4) {
			side = 0;
			layer = 2;
		}

		Color prim  = _cube.get_edges()[_cornersMap[i][0][0]][_cornersMap[i][0][1]][_cornersMap[i][0][2]];
		Color side1 = _cube.get_edges()[_cornersMap[i][1][0]][_cornersMap[i][1][1]][_cornersMap[i][1][2]];
		Color side2 = _cube.get_edges()[_cornersMap[i][2][0]][_cornersMap[i][2][1]][_cornersMap[i][2][2]];
		if (prim == WHITE) {
			_whitesCorn[addedCorners] = new Corner(ElementLocLayer(layer), side, prim, side1, side2, 0);
			addedCorners++;
		}
		else if (side1 == WHITE){
			_whitesCorn[addedCorners] = new Corner(ElementLocLayer(layer), side, prim, side1, side2, 1);
			addedCorners++;
		}
		else if (side2 == WHITE) {
			_whitesCorn[addedCorners] = new Corner(ElementLocLayer(layer), side, prim, side1, side2, 2);
			addedCorners++;
		}
	}
	// ���� ����� ������ 4 �������, �� ���-�� ��������, ���� ������������ ������ ��� ��� ������������ �����
	if (addedCorners < NUM_OF_WHITES) return nullptr;

	return (const Element **)_whitesCorn;
}