#include "Assembler.h"

Assembler::Assembler(Cube & c) : _cube(c) {
	_analyser = new Analyser(_cube);
}

Assembler::~Assembler() {
	delete _analyser;
}



void Assembler::allignCube(Formula & res) {
	int topPos = findMidColor(WHITE);

	switch (topPos)
	{
	case 1: {
		res.sequence.push_back(Operation{ z, CKW });
		break;
	}
	case 2: {
		res.sequence.push_back(Operation{ x, CKW });
		break;
	}
	case 3: {
		res.sequence.push_back(Operation{ z, ACKW });
		break;
	}
	case 4: {
		res.sequence.push_back(Operation{ x, ACKW });
		break;
	}
	case 5: {
		res.sequence.push_back(Operation{ z, DOUBL });
		break;
	}
	default:
		break;
	}

	int frontPos = findMidColor(BLUE);

}

void Assembler::doTopCross(Formula & res) {
	 Edge const ** whitesEdge;

	whitesEdge = _analyser->findWhitesEdge();
	
	for (int i = 0; i < NUM_OF_WHITES; i++) { // Начинаю с конца потому, что там должны быть кубики с нижних слоев
		if (whitesEdge[i]->placed == false) {
			switch (whitesEdge[i]->layer) {
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


// +++++++++++ Приватные функции +++++++++++++
int Assembler::findMidColor(Color color) {
	int res = -1;
	for (int i = 0; i < 6; i++) {
		if (_cube.get_edges()[i][1][1] == color)
			res = i;
	}
	return res;
}

//Operation Assembler::findOptimalYRot(int src, int tgt) {
//	
//}