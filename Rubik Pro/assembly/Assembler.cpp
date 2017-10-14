#include <cassert>
#include "Assembler.h"
#include "..\control\Master.h"

Assembler::Assembler(Cube & c) : _cube(c), _liveCube(c){
	_analyser = new Analyser(_liveCube);
}

Assembler::~Assembler() {
	delete _analyser;
}

void Assembler::allignCube(Formula & res, Color colorOnTop, Color colorOnFront) {
	assert(colorOnTop != colorOnFront); // ÷вета верхнего и нижнего центрального элемента не могут совпадать
	_liveCube = _cube;

	int topPos = findMidColor(colorOnTop, _liveCube);

	switch (topPos)
	{
	case 1: {
		applyOperation(res, Operation{ z, CKW });
		break;
	}
	case 2: {
		applyOperation(res, Operation{ x, ACKW });
		break;
	}
	case 3: {
		applyOperation(res, Operation{ z, ACKW });
		break;
	}
	case 4: {
		applyOperation(res, Operation{ x, CKW });
		break;
	}
	case 5: {
		applyOperation(res, Operation{ z, DOUBL });
		break;
	}
	default:
		break;
	}

	int frontPos = findMidColor(colorOnFront, _liveCube);
	applyOperation(res, Operation{ y, findOptimalYRot(sideCoordOfEdgeToAdvancedPos(frontPos), 2) });
}

void Assembler::doTopCross(Formula & res) {
	_liveCube = _cube;
	_edgeVector whitesEdge;
	_analyser->findWhitesEdge(whitesEdge);

	for (int i = 0; i < NUM_OF_WHITES; i++) { 
		Edge & x = *whitesEdge[i].first;
		if (x.placed == false) {
			switch (x.layer) {
			case TOP: {

				break;
			}
			case MID: {

				break;
			}
			case BOT: {
				allignCube(res, WHITE, x.get_second());

				_analyser->findWhitesEdge(whitesEdge);

				//findOptimalYRot()
				break;
			}
			default:
				break;
			}

		}
	}
}


