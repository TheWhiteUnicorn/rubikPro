#include "..\Assembler.h"

#define curCorn whitesCorn[i]

void Assembler::doTopLayer(FormulaStack & res) {
	_liveCube = _cube;
	allign(res, YELLOW, GREEN);

	_cornVector & whitesCorn = _analyser->findWhitesCorn();

	for (int i = 0; i < NUM_OF_WHITES; i++) {	
		if (!curCorn->placed) {
			_analyser->findWhitesCorn();
			switch (curCorn->layer) {
			case BOT: {
				if (curCorn->get_side1() == _liveCube.get_edges()[advToSide((curCorn->side) + 1)][1][1]) {
					allign(res, YELLOW, curCorn->get_side1());

					switch (curCorn->get_orientation()) {
					case 1: {
						applyOperation(res, R, CKW);
						applyOperation(res, U, ACKW);
						applyOperation(res, R, DOUBL);
						applyOperation(res, F, CKW);
						applyOperation(res, R, CKW);
						applyOperation(res, F, ACKW);
						break;
					}
					case 2: {
						for (int i = 0; i < 2; i++) {
							applyOperation(res, R, CKW);
							applyOperation(res, U, CKW);
							applyOperation(res, R, ACKW);
							applyOperation(res, U, ACKW);
						}
						break;
					}
					}
					break;
				}
				else {
					allign(res, YELLOW, _liveCube.get_edges()[(advToSide((curCorn->side) + 1))][1][1]);
					applyOperation(res, R, CKW);
					applyOperation(res, U, ACKW);
					applyOperation(res, R, ACKW);
					
				}
			}
			case TOP: {
				allign(res, YELLOW, curCorn->get_side1());
				_analyser->findWhitesCorn();
				applyOperation(res, U, findOptimalYRot(curCorn->side, 1, TOP));
					switch (curCorn->get_orientation()) {
					case 0: {
						applyOperation(res, R, CKW);
						applyOperation(res, U, DOUBL);
						applyOperation(res, R, ACKW);
						applyOperation(res, U, DOUBL);
						applyOperation(res, F, ACKW);
						applyOperation(res, U, CKW);
						applyOperation(res, F, CKW);
						break;
					}
					case 1: {
						applyOperation(res, R, CKW);
						applyOperation(res, U, CKW);
						applyOperation(res, R, ACKW);
						break;
					}
					case 2: {
						applyOperation(res, F, ACKW);
						applyOperation(res, U, ACKW);
						applyOperation(res, F, CKW);
						break;
					}
					}
				break;
			}
			default:
				break;
			}
		}

		curCorn->placed = true;
		res.newFormula();
	}
}