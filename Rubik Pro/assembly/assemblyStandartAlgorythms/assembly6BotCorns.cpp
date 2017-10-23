#include"..\Assembler.h"

#define frontEdgeAdgustment 	Color topLeftCornerColor = _liveCube.get_color(2, 9); \
								_liveCube.rotate(x, ACKW); \
								Dir rotDirection = findOptimalYRot(sideToAdv(findMidColor(topLeftCornerColor, _liveCube)), 2, BOT);	\
								_liveCube.rotate(x, CKW); \
								applyOperation(res, Fw, rotDirection);

void Assembler::doBotCorns(FormulaStack & res) {
	_liveCube = _cube;
	
	Color colorOnTop; // ÷вет, которого должен быть центральный правый елемент, чтоб "ситуаци€" сто€ла на своем месте
	int situation = _analyser->findBotCornsConfig(colorOnTop);

	switch (situation) {
	case 0: {
		allign(res, colorOnTop, WHITE);

		frontEdgeAdgustment

		applyOperation(res, BOT_CORNS_CYCLIC_SHIFT_ACKW);
		break;
	}
	case 1: {
		allign(res, colorOnTop, WHITE);

		frontEdgeAdgustment

		applyOperation(res, BOT_CORNS_CYCLIC_SHIFT_CKW);
		break;
	}
	case 2: {
		applyOperation(res, BOT_CORNS_DIAGONAL_SWITCH);
		frontEdgeAdgustment

		break;
	}
	case 3: {
		Color topLeftCornerColor = _liveCube.get_color(0, 1); 
		Dir rotDirection = findOptimalYRot(sideToAdv(findMidColor(topLeftCornerColor, _liveCube)), 2, BOT);
		applyOperation(res, U, rotDirection);
		break;
	}
	default:
		throw 1;
	}
}