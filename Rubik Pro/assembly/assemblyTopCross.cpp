#include "Assembler.h"

//#define invD(dir) dir == 2 ? dir : Dir(1 - int(dir))
#define whitesFirst whitesEdge[i].first

void Assembler::doTopCross(Formula & res) {
	_liveCube = _cube;
	
	 _edgeVector & whitesEdge = _analyser->findWhitesEdge();

	for (int i = 0; i < NUM_OF_WHITES; i++) {
		//Edge * x = whitesEdge[i].first;
		_analyser->findWhitesEdge();
		if (whitesFirst->placed == false) {

			switch (whitesFirst->layer) {
			case TOP: {

				break;
			}
			case MID: {
				
				if(whitesFirst->get_orientation() == 0){
					allign(res, WHITE, _liveCube.get_edges()[(AdvancedPosToSideCoordOfEdge())][1][1]);
					//applyOperation(res, U, findOptimalYRot());
				} else {

				}
				break;
			}
			case BOT: {
				allign(res, WHITE, whitesFirst->get_second());
				_analyser->findWhitesEdge();
				applyOperation(res, D, findOptimalYRot(whitesFirst->side.side, 2, BOT));
				if (whitesFirst->get_orientation() == 0) {
					applyOperation(res, F, DOUBL);
					whitesFirst->placed = true;
				}
				else {
					applyOperation(res, D, CKW);
					applyOperation(res, R, CKW);
					applyOperation(res, F, ACKW);
					applyOperation(res, R, ACKW);
					whitesFirst->placed = true;
				}
				break;
			}
			default:
				break;
			}

		}
	}
}
