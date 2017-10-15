#include "Assembler.h"

//#define invD(dir) dir == 2 ? dir : Dir(1 - int(dir))
#define whitesFirst whitesEdge[i].first //TODO убрать это

void Assembler::doTopCross(Formula & res) {
	_liveCube = _cube;
	
	 _edgeVector & whitesEdge = _analyser->findWhitesEdge();

	for (int i = 0; i < NUM_OF_WHITES; i++) {
		//Edge * x = whitesEdge[i].first;
		_analyser->findWhitesEdge();
		if (whitesFirst->placed == false) {

			switch (whitesFirst->layer) {
			case TOP: {
				allign(res, WHITE, _liveCube.get_edges()[(advToSide((whitesFirst->side)))][1][1]);
				_analyser->findWhitesEdge();
				if (_liveCube.get_edges()[0][1][1] == whitesFirst->get_second()) {
					if (whitesFirst->get_orientation() != 0) {
						applyOperation(res, F, CKW);
						applyOperation(res, U, ACKW);
						applyOperation(res, R, CKW);
						applyOperation(res, U, CKW);
					}
				}
				else {
					if (whitesFirst->get_orientation() == 0) {
						applyOperation(res, F, CKW);
						Operation& tmp = applyOperation(res, U, findOptimalYRot(sideToAdv(findMidColor(whitesFirst->get_second(), _liveCube)).side, 2, TOP));
						applyOperation(res, F, ACKW);
						applyOperation(res, tmp.invert());
					}
					else {
						applyOperation(res, F, CKW);
						Operation& tmp = applyOperation(res, U, findOptimalYRot(sideToAdv(findMidColor(whitesFirst->get_second(), _liveCube)).side, 1, TOP));
						applyOperation(res, R, CKW);
						applyOperation(res, tmp);
					}
				}
				
				break;
			}
			case MID: {
				
				if(whitesFirst->get_orientation() == 0){
					allign(res, WHITE, _liveCube.get_edges()[(advToSide(++(whitesFirst->side)))][1][1]);
					Operation& tmp = applyOperation(res, U, findOptimalYRot( sideToAdv(findMidColor(whitesFirst->get_second(), _liveCube)).side, 2, TOP));
					applyOperation(res, F, ACKW);
					applyOperation(res, tmp.invert());
				} else {
					allign(res, WHITE, _liveCube.get_edges()[(advToSide((whitesFirst->side)))][1][1]);
					Operation& tmp = applyOperation(res, U, findOptimalYRot( sideToAdv(findMidColor(whitesFirst->get_second(), _liveCube)).side, 2, TOP));
					applyOperation(res, F, CKW);
					applyOperation(res, tmp.invert());
				}
				break;
			}
			case BOT: {
				allign(res, WHITE, whitesFirst->get_second());
				_analyser->findWhitesEdge();
				applyOperation(res, D, findOptimalYRot(whitesFirst->side.side, 2, BOT));
				if (whitesFirst->get_orientation() == 0) {
					applyOperation(res, F, DOUBL);
				}
				else {
					applyOperation(res, D, CKW);
					applyOperation(res, R, CKW);
					applyOperation(res, F, ACKW);
					applyOperation(res, R, ACKW);
				}
				break;
			}
			default:
				break;
			}

			whitesFirst->placed = true;
		}
	}
}
