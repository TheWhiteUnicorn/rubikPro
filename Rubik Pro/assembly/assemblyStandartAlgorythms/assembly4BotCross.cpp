#include "..\Assembler.h"

void Assembler::doBotCross(FormulaStack & res) {
	_liveCube = _cube;
	setSPurp(HS_STACK_4);

	Dir allignRotDirection;
	YellowCrossSituation situation = _analyser->findYellowCrossSituations(allignRotDirection);
	applyOperation(res, y, allignRotDirection);

	switch (situation)
	{
	case STICK:
		setFPurp(HS_FORM_YLW_CROSS_STICK);
		applyOperation(res, BOT_CROSS_STICK);
		break;
	case DAW:
		setFPurp(HS_FORM_YLW_CROSS_DAW);
		applyOperation(res, BOT_CROSS_DAW);
		break;
	case DOT:
		setFPurp(HS_FORM_YLW_CROSS_DOT);
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