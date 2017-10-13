#include <cassert>
#include "Assembler.h"
#include "..\control\Master.h"

Assembler::Assembler(Cube & c) : _cube(c), _liveCube(c){
	_analyser = new Analyser(_cube);
}

Assembler::~Assembler() {
	delete _analyser;
}

void Assembler::allignCube(Formula & res) {
	_liveCube = _cube;

	int topPos = findMidColor(WHITE, _liveCube);

	switch (topPos)
	{
	case 1: {
		res.push_back(Operation{ z, CKW });
		break;
	}
	case 2: {
		res.push_back(Operation{ x, ACKW });
		break;
	}
	case 3: {
		res.push_back(Operation{ z, ACKW });
		break;
	}
	case 4: {
		res.push_back(Operation{ x, CKW });
		break;
	}
	case 5: {
		res.push_back(Operation{ z, DOUBL });
		break;
	}
	default:
		break;
	}

	_liveCube.rotate(res.get_sequence().back());
	dispEdges(_liveCube.get_edges());
	int frontPos = findMidColor(BLUE, _liveCube);
	res.push_back(Operation{ y, findOptimalYRot(sideCoordOfEdgeToAdvancedPos(frontPos), 2) });
}

void Assembler::doTopCross(Formula & res) {
	_edgeVector whitesEdge;

	whitesEdge = _analyser->findWhitesEdge();
	
	for (int i = 0; i < NUM_OF_WHITES; i++) { // Ќачинаю с конца потому, что там должны быть кубики с нижних слоев

		if (whitesEdge[i].first->placed == false) {
			switch (whitesEdge[i].first->layer) {
			case TOP: {

				break;
			}
			case MID: {

				break;
			}
			case BOT: {

				break;
			}
			default:
				break;
			}

		}
	}
}


// +++++++++++ ѕриватные функции +++++++++++++
int Assembler::findMidColor(Color color, Cube & cube) {
	int res = -1;
	for (int i = 0; i < 6; i++) {
		if (cube.get_edges()[i][1][1] == color) {
			res = i;
			break;
		}
	}
	return res;
}

Dir Assembler::findOptimalYRot(int src, int tgt) {
	Dir answ;
	int diff = src - tgt;

	diff = diff == -2 ? 2 : diff; // замен€ем -2 на 2

	switch (diff)
	{
	case -1: {
		answ = CKW;
		break;
	}
	case 0: {
		answ = NONE;
		break;
	}
	case 1: {
		answ = ACKW;
		break;
	}
	case 2: {
		answ = DOUBL;
		break;
	}
	case 3: {
		answ = CKW;
		break;
	}	
	case -3: {
		answ = ACKW;
		break;
	}
	default:
		break;
	}
	return answ;
}

//јвтоматическое преобразование из кода боковой грани (1-4) в код по расширенной системе позиционировани€ (только дл€ координат ребер!)
int Assembler::sideCoordOfEdgeToAdvancedPos(int side) {
	assert(side >= 1 && side <= 4);

	switch (side) {
	case 1: return 3;
	case 2: return 0;
	case 3: return 1;
	case 4: return 2;
	}
}