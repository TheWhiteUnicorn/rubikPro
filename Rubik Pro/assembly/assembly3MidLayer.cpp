#include "Assembler.h"

#define MOVE_TO_LEFT	applyOperation(res, U, ACKW);\
						applyOperation(res, L, ACKW);\
						applyOperation(res, U, ACKW);\
						applyOperation(res, L, CKW);\
						applyOperation(res, U, CKW);\
						applyOperation(res, F, CKW);\
						applyOperation(res, U, CKW);\
						applyOperation(res, F, ACKW);

#define MOVE_TO_RIGHT 	applyOperation(res, U, CKW);\
						applyOperation(res, R, CKW);\
						applyOperation(res, U, ACKW);\
						applyOperation(res, R, ACKW);\
						applyOperation(res, F, CKW);\
						applyOperation(res, R, ACKW);\
						applyOperation(res, F, ACKW);\
						applyOperation(res, R, CKW);


#define curEdge midEdge[sortedAssocMap[i]]

// ¬спомогательна€ функци€, сорирует карту ассоциаций, начина€ с первого необработанного элемента (begin), и выталкива€ элементы средних слоев в конец (на работает дл€ нижнего сло€!)
void sortAssocMap(int* map, _edgeVector& edges, int begin) {
	assert(begin < 4);

	int counter = begin;
	int mapNew[4];
	for (int i = begin; i < NUM_OF_MID_EDGES; i++) {
		if (edges[map[i]]->layer == TOP)
			mapNew[counter++] = map[i];
	}
	for (int i = begin; i < NUM_OF_MID_EDGES; i++) {
		if (edges[map[i]]->layer == MID)
			mapNew[counter++] = map[i];

		map[i] = mapNew[i]; // все значени€ сразу перекидываютс€ в map
	}
	
}

void Assembler::doMidLayer(FormulaStack & res) {
	_liveCube = _cube;

	_edgeVector & midEdge = _analyser->findMidEdge();
	
	//  арта, отображающа€ то, в каком пор€дке должны обрабатыватьс€ грани (начинать надо с тех, которые расположены на верхнем слое)
	int sortedAssocMap[4]{0, 1, 2, 3};
	//sortAssocMap(sortedAssocMap, midEdge, 0);

	for (int i = 0; i < NUM_OF_MID_EDGES; i++) {
		_analyser->findMidEdge();
		sortAssocMap(sortedAssocMap, midEdge, i);
		if (curEdge->layer == MID) { // если элемент на середине, мы ее поднимаеми потом обработаем как элемент с верхнего сло€
			if (_liveCube.get_edges()[(advToSide((curEdge->side)))][1][1] != curEdge->get_second() || curEdge->get_orientation() == 0) { //провер€ем, не стоит ли элемент уже на месте

				allign(res, YELLOW, _liveCube.get_edges()[(advToSide((curEdge->side)+1))][1][1]);

				MOVE_TO_RIGHT

				_analyser->findMidEdge();
			}
		}

		if (curEdge->layer == TOP) {
			if (curEdge->get_orientation() == 0) {
				allign(res, YELLOW, curEdge->get_second());
 				_analyser->findMidEdge();
				applyOperation(res, U, findOptimalYRot(curEdge->side, 2, TOP));

				MOVE_TO_LEFT
			}
			else {
				allign(res, YELLOW, curEdge->get_first());
				_analyser->findMidEdge();
				applyOperation(res, U, findOptimalYRot(curEdge->side, 2, TOP));

				MOVE_TO_RIGHT
			}
		}

		curEdge->placed = true;
		res.newFormula();
		
	}
}