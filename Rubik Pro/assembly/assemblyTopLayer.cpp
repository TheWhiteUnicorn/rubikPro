#include "Assembler.h"

#define curCorn whitesCorn[i]

void Assembler::doTopLayer(FormulaStack & res) {
	_liveCube = _cube;

	_cornVector & whitesCorn = _analyser->findWhitesCorn();

	for (int i = 0; i < NUM_OF_WHITES; i++) {

		_analyser->findWhitesCorn();
		allign(res, YELLOW, curCorn->get_side1);
		if (!curCorn->placed) {
			switch (curCorn->layer) {
			case BOT: {
				
			}
			case TOP: {
				applyOperation(res, U, findOptimalYRot(curCorn->side, 2, TOP));
				switch (curCorn->get_orientation()) {

				}
				break;
			}
			default:
				break;
			}
		}
	}
}