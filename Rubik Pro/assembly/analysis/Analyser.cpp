#include "Analyser.h"
#include <assert.h>

Analyser::Analyser(Cube & cube) : _cube(cube) {
	_whitesCorn.resize(NUM_OF_WHITES);
	_whitesEdge.resize(NUM_OF_WHITES);
	_midEdges.resize(NUM_OF_MID_EDGES);

	for (int i = 0; i < NUM_OF_WHITES; i++) {
		_whitesEdge[i] = new Edge(TOP, 0, WHITE, Color(i+1), 0);

		Color secCornColor = (i == 4) ? Color(1) : Color(i + 2);
		_whitesCorn[i] = new Corner(TOP, 0, WHITE, Color(i+1), secCornColor, 0);
	}

	for (int i = 0; i < NUM_OF_MID_EDGES; i++) {
		_midEdges[i] = new Edge(TOP, 0, Color(i+1), sideEdgesAssoc[Color(i+1)], 0);
	}
}

Analyser::~Analyser() {
	for (int i = 0; i < NUM_OF_WHITES; i++) {
		delete _whitesCorn[i];
		delete _whitesEdge[i];
	}
	for (int i = 0; i < NUM_OF_MID_EDGES; i++) {
		delete _midEdges[i];
	}
}

//bool cmpEdgeVectorsBySecondColor(pair<Edge*, bool> x, pair<Edge*, bool> y) {
//	return x.first->get_second() < y.first->get_second();
//}

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
			addedEdges++;
		}
		else if (second == WHITE) {
			_whitesEdge[int(first) - 1]->set(ElementLocLayer(layer), side, first, second, 1);
			addedEdges++;
		}
	}

	return _whitesEdge;
}

_cornVector& Analyser::findWhitesCorn() {

	int addedCorners = 0;
	// +++++++++++++++ Ищем белые уголки +++++++++++++++++
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

_edgeVector & Analyser::findMidEdge() { //TODO Оптимизировать, чтоб функция не искала, если уже нашла 4 элемента
	int addedEdges = 0;

	for (int i = 0, side = 0, layer = 0; i < 12; i++, side++) {
		if (side == 4) {
			side = 0;
			layer++;
		}

		Color first = _cube.get_edges()[_edgesMap[i][0][0]][_edgesMap[i][0][1]][_edgesMap[i][0][2]];
		Color second = _cube.get_edges()[_edgesMap[i][1][0]][_edgesMap[i][1][1]][_edgesMap[i][1][2]];

		if ((first != WHITE && second != WHITE) && (first != YELLOW && second != YELLOW)) {

			int orientation; 
			Color tmp = sideEdgesAssoc[first];
			if (tmp == second)
				orientation = 0;
			else
				orientation = 1;

			if (orientation == 0) {
				_midEdges[int(first) - 1]->set(ElementLocLayer(layer), side, first, second, 0);
				addedEdges++;
			}
			else if (orientation == 1) {
				_midEdges[int(second) - 1]->set(ElementLocLayer(layer), side, first, second, 1);
				addedEdges++;
			}
		}
	}

	if (addedEdges != 4) throw 1;
	return _midEdges;
}


YellowCrossSituation Analyser::findYellowCrossSituations(Dir& res) {
	assert(_cube.get_edges()[2][1][1] == YELLOW);
	res = NONE;

	int yellowsCounter = 0; // считает желтые наклейки на крестовых элементах
	for (int i = 2; i <= 8; i += 2) {
		if (_cube.get_color(2, i) == YELLOW) yellowsCounter++;
	}

	switch (yellowsCounter)	{
	case 0: return DOT;
	case 4: return CROSS;
	case 2: {
		Cube tmpCube(_cube);

		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 1: {res = CKW;	break;}
			case 2: {res = DOUBL; break;}
			case 3: {res = ACKW; break;}}

			if (tmpCube.get_color(2, 6) == YELLOW && tmpCube.get_color(2, 8) == YELLOW)
				return DAW;
			if (tmpCube.get_color(2, 6) == YELLOW && tmpCube.get_color(2, 4) == YELLOW)
				return STICK;

			tmpCube.rotate(U, CKW);
		}

		break;
	}
	default: 
		break;
	}
	throw 1; // Situation not found
}

// вспом. функция для findYellowLayerSituations, преобразует значения счетчика цикла в направление вращения
Dir iToDir(int i) {
	switch (i) {
		case 0: return NONE;
		case 1: return CKW;
		case 2: return DOUBL;
		case 3: return ACKW;
	}
}

YellowLayerSituation Analyser::findYellowLayerSituations(Dir & res) {
	assert(_cube.get_edges()[2][1][1] == YELLOW);

	int yellowsCornCount = 0; // считает наклейки на угловых элементах, которые направлены вниз
	for (int i = 1; i <= 9; i += 2) {
		if (_cube.get_color(2, i) == YELLOW) yellowsCornCount++;
	}
	yellowsCornCount--; // вычитаем центральную наклейку

	Cube tmpCube(_cube);

	switch (yellowsCornCount) {
	case 4: return LAYER_DONE;
	case 0: {
		for (int i = 0; i < 4; i++) {
			res = iToDir(i);
				
			if		   (tmpCube.get_color(1, 7) == YELLOW &&
						tmpCube.get_color(5, 9) == YELLOW &&
						tmpCube.get_color(0, 3) == YELLOW &&
						tmpCube.get_color(1, 1) == YELLOW )
						return HELI;
			else if	   (tmpCube.get_color(1, 7) == YELLOW &&
						tmpCube.get_color(3, 9) == YELLOW &&
						tmpCube.get_color(3, 3) == YELLOW &&
						tmpCube.get_color(1, 1) == YELLOW)
						return D_EYES;

			tmpCube.rotate(U, CKW);
		}
		break;
	}
	case 1: {
		for (int i = 0; i < 4; i++) {
			res = iToDir(i);

			if		   (tmpCube.get_color(1, 7) == YELLOW &&
						tmpCube.get_color(0, 1) == YELLOW &&
						tmpCube.get_color(3, 3) == YELLOW)
						return L_FISH;
			else if	   (tmpCube.get_color(5, 7) == YELLOW &&
						tmpCube.get_color(3, 9) == YELLOW &&
						tmpCube.get_color(0, 3) == YELLOW)
						return R_FISH;

			tmpCube.rotate(U, CKW);
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 4; i++) {
			res = iToDir(i);

			if		   (tmpCube.get_color(2, 9) == YELLOW &&
						tmpCube.get_color(2, 1) == YELLOW &&
						tmpCube.get_color(1, 1) == YELLOW &&
						tmpCube.get_color(5, 9) == YELLOW)
						return EIGHT;
			else if	   (tmpCube.get_color(2, 3) == YELLOW &&
						tmpCube.get_color(2, 1) == YELLOW &&
						tmpCube.get_color(5, 7) == YELLOW &&
						tmpCube.get_color(5, 9) == YELLOW)
						return EYES;
			else if    (tmpCube.get_color(2, 7) == YELLOW &&
						tmpCube.get_color(2, 1) == YELLOW &&
						tmpCube.get_color(5, 7) == YELLOW &&
						tmpCube.get_color(0, 1) == YELLOW)
						return EARS;

			tmpCube.rotate(U, CKW);
		}
		break;
	}
	}
	throw 1; // Situation not found
}