#include "Assembler.h"

#define curEdge whitesEdge[i]

void Assembler::doTopCross(FormulaStack & res) {
	_liveCube = _cube;
	
	 _edgeVector & whitesEdge = _analyser->findWhitesEdge();

	for (int i = 0; i < NUM_OF_WHITES; i++) {
		_analyser->findWhitesEdge();
		if (curEdge->placed == false) {

			switch (curEdge->layer) {
			case TOP: {
				allign(res, WHITE, _liveCube.get_edges()[(advToSide((curEdge->side)))][1][1]);
				_analyser->findWhitesEdge();
				if (_liveCube.get_edges()[0][1][1] == curEdge->get_second()) {
					if (curEdge->get_orientation() != 0) {
						applyOperation(res, F, CKW);
						applyOperation(res, U, ACKW);
						applyOperation(res, R, CKW);
						applyOperation(res, U, CKW);
					}
				}
				else {
					if (curEdge->get_orientation() == 0) {
						applyOperation(res, F, CKW);
						Operation& tmp = applyOperation(res, U, findOptimalYRot(sideToAdv(findMidColor(curEdge->get_second(), _liveCube)).side, 2, TOP));
						applyOperation(res, F, ACKW);
						applyOperation(res, tmp.invert());
					}
					else {
						applyOperation(res, F, CKW);
						Operation& tmp = applyOperation(res, U, findOptimalYRot(sideToAdv(findMidColor(curEdge->get_second(), _liveCube)).side, 1, TOP));
						applyOperation(res, R, CKW);
						applyOperation(res, tmp);
					}
				}
				
				break;
			}
			case MID: {
				
				if(curEdge->get_orientation() == 0){
					allign(res, WHITE, _liveCube.get_edges()[(advToSide(++(curEdge->side)))][1][1]);
					Operation& tmp = applyOperation(res, U, findOptimalYRot( sideToAdv(findMidColor(curEdge->get_second(), _liveCube)).side, 2, TOP));
					applyOperation(res, F, ACKW);
					applyOperation(res, tmp.invert());
				} else {
					allign(res, WHITE, _liveCube.get_edges()[(advToSide((curEdge->side)))][1][1]);
					Operation& tmp = applyOperation(res, U, findOptimalYRot( sideToAdv(findMidColor(curEdge->get_second(), _liveCube)).side, 2, TOP));
					applyOperation(res, F, CKW);
					applyOperation(res, tmp.invert());
				}
				break;
			}
			case BOT: {
				allign(res, WHITE, curEdge->get_second());
				_analyser->findWhitesEdge();
				applyOperation(res, D, findOptimalYRot(curEdge->side.side, 2, BOT));
				if (curEdge->get_orientation() == 0) {
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

			curEdge->placed = true;
			res.newFormula();
		}
	}
}
