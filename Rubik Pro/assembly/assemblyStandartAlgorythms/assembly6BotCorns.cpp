#include"..\Assembler.h"

#define frontEdgeAdgustment 	Color topLeftCornerColor = _liveCube.get_color(2, 9); \
								_liveCube.rotate(x, ACKW); \
								Dir rotDirection = findOptimalYRot(sideToAdv(findMidColor(topLeftCornerColor, _liveCube)), 2, BOT);	\
								_liveCube.rotate(x, CKW); \
								applyOperation(res, Fw, rotDirection);

void Assembler::doBotCorns(FormulaStack & res) {
	_liveCube = _cube;
	
	Color colorOnTop; // ÷вет, которого должен быть центральный правый елемент, чтоб "ситуаци€" сто€ла на своем месте
	BotCornsSituation situation = _analyser->findBotCornsConfig(colorOnTop);

	switch (situation) {
	case BOT_C_CYCLIC_SHIFT_ACKW: {
		allign(res, colorOnTop, WHITE);

		frontEdgeAdgustment

		applyOperation(res, BOT_CORNS_CYCLIC_SHIFT_ACKW);
		applyOperation(res, x, ACKW);
		break;
	}
	case BOT_C_CYCLIC_SHIFT_CKW: {
		allign(res, colorOnTop, WHITE);

		frontEdgeAdgustment

		applyOperation(res, BOT_CORNS_CYCLIC_SHIFT_CKW);
		applyOperation(res, x, ACKW);
		break;
	}
	case BOT_C_DIAGONAL_SWITCH: {
		applyOperation(res, BOT_CORNS_DIAGONAL_SWITCH);
		Color topLeftCornerColor = _liveCube.get_color(0, 1);
		Dir rotDirection = findOptimalYRot(sideToAdv(findMidColor(topLeftCornerColor, _liveCube)), 2, BOT);
		applyOperation(res, U, rotDirection);
		break;
	}
	case BOT_C_DONE: {
		Color topLeftCornerColor = _liveCube.get_color(0, 1); 
		Dir rotDirection = findOptimalYRot(sideToAdv(findMidColor(topLeftCornerColor, _liveCube)), 2, BOT);
		applyOperation(res, U, rotDirection);
		break;
	}
	default:
		throw 1;
	}
}