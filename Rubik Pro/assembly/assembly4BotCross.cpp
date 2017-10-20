#include "Assembler.h"

void Assembler::doBotCross(FormulaStack & res) {
	_liveCube = _cube;

	Dir allignRotDirection;
	YellowCrossSituation situation = _analyser->findYellowCrossSituations(allignRotDirection);
	applyOperation(res, y, allignRotDirection);

	switch (situation)
	{
	case STICK:
		applyOperation(res, BOT_CROSS_STICK);
		break;
	case DAW:
		applyOperation(res, BOT_CROSS_DAW);
		break;
	case DOT:
		applyOperation(res, BOT_CROSS_STICK);
		applyOperation(res, U, DOUBL);
		applyOperation(res, BOT_CROSS_DAW);
		break;
	case CROSS:
		break;
	default:
		break;
	}

}