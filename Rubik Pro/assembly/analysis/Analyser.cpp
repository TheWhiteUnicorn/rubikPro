#include "Analyser.h"
#include <algorithm>

Analyser::Analyser(Cube & cube) : _cube(cube) {
	_whitesCorn.resize(NUM_OF_WHITES);
	_whitesEdge.resize(NUM_OF_WHITES);
	for (int i = 0; i < NUM_OF_WHITES; i++) {
		_whitesEdge[i] = new Edge(TOP, 0, WHITE, Color(i+1), 0);

		Color secCornColor = (i == 4) ? Color(1) : Color(i + 2);
		_whitesCorn[i] = new Corner(TOP, 0, WHITE, Color(i+1), secCornColor, 0);
	}
}

Analyser::~Analyser() {
	for (int i = 0; i < NUM_OF_WHITES; i++) {
		delete _whitesCorn[i];
		delete _whitesEdge[i];
	}
	/*for (int i = 0; i < NUM_OF_YELLOWS; i++) {
		delete _yellows[i];
	}
	for (int i = 0; i < NUM_OF_SIDE_EDGES; i++) {
		delete _sideEdges[i];
	}
	/*for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
		delete _elements[i];
	}*/
}

//
bool cmpEdgeVectorsBySecondColor(pair<Edge*, bool> x, pair<Edge*, bool> y) {
	return x.first->get_second() < y.first->get_second();
}

void Analyser::refresh() {
	for (int i = 0; i < NUM_OF_WHITES; i++) {
		_whitesEdge[i]->placed = false;
		_whitesCorn[i]->placed = false;
	}
}

_edgeVector& Analyser::findWhitesEdge() {

	int addedEdges = 0;
	for (int i = 0, side = 0, layer = 0; i < 12; i++, side++) {
		if (side == 4) {
			side = 0;
			layer++;
		}

		Color first = _cube.get_edges()[_edgesMap[i][0][0]][_edgesMap[i][0][1]][_edgesMap[i][0][2]];
		Color second = _cube.get_edges()[_edgesMap[i][1][0]][_edgesMap[i][1][1]][_edgesMap[i][1][2]];
		if (first == WHITE) {
			_whitesEdge[int(second) - 1]->set(ElementLocLayer(layer), side, first, second, 0);
			//_whitesEdge[int(second) - 1].second = true;
			addedEdges++;
		}
		else if (second == WHITE) {
			_whitesEdge[int(first) - 1]->set(ElementLocLayer(layer), side, first, second, 1);
			//_whitesEdge[int(first) - 1].second = true;
			addedEdges++;
		}
	}

	return _whitesEdge;
}

_cornVector& Analyser::findWhitesCorn() {

	int addedCorners = 0;
	// +++++++++++++++ »щем белые уголки +++++++++++++++++
	for (int i = 0, side = 0, layer = 0; i < 8; i++, side++) {
		if (side == 4) {
			side = 0;
			layer = 2;
		}

		Color prim  = _cube.get_edges()[_cornersMap[i][0][0]][_cornersMap[i][0][1]][_cornersMap[i][0][2]];
		Color side1 = _cube.get_edges()[_cornersMap[i][1][0]][_cornersMap[i][1][1]][_cornersMap[i][1][2]];
		Color side2 = _cube.get_edges()[_cornersMap[i][2][0]][_cornersMap[i][2][1]][_cornersMap[i][2][2]];
		if (prim == WHITE) {
			_whitesCorn[int(side1) - 1]->set(ElementLocLayer(layer), side, prim, side1, side2, 0);
			//_whitesCorn[int(side1)].second = true;
			addedCorners++;
		}
		else if (side1 == WHITE){
			_whitesCorn[int(side2) - 1]->set(ElementLocLayer(layer), side, prim, side1, side2, 1);
			addedCorners++;
		}
		else if (side2 == WHITE) {
			_whitesCorn[int(prim) - 1]->set(ElementLocLayer(layer), side, prim, side1, side2, 2);			
			addedCorners++;
		}
	}

	return _whitesCorn;
}

