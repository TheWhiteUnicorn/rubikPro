#include "..\Assembler.h"
//#include "..\formulasLib.h"

void Assembler::doBotFacet(FormulaStack & res) {
	_liveCube = _cube;
	setSPurp(HS_STACK_5);

	Dir allignRotDirection;
	YellowLayerSituation situation = _analyser->findYellowLayerSituations(allignRotDirection);
	applyOperation(res, y, allignRotDirection);

	switch (situation)
	{
	case L_FISH: {
		applyOperation(res, BOT_FACET_L_FISH);
		break;
	}
	case R_FISH: {
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EYES: {
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, ACKW);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EARS: {
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EIGHT: {
		applyOperation(res, U, DOUBL);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, DOUBL);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case D_EYES: {
		applyOperation(res, BOT_FACET_R_FISH);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case HELI: {
		applyOperation(res, BOT_FACET_R_FISH);
		applyOperation(res, U, ACKW);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case LAYER_DONE:
		break;
	default:
		break;
	}
}