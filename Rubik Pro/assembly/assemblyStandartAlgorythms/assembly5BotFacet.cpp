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
		setFPurp(HS_FORM_YLW_LYR_L_FISH);
		applyOperation(res, BOT_FACET_L_FISH);
		break;
	}
	case R_FISH: {
		setFPurp(HS_FORM_YLW_LYR_R_FISH);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EYES: {
		setFPurp(HS_FORM_YLW_LYR_EYES);
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, ACKW);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EARS: {
		setFPurp(HS_FORM_YLW_LYR_EARS);
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case EIGHT: {
		setFPurp(HS_FORM_YLW_LYR_EIGHT);
		applyOperation(res, U, DOUBL);
		applyOperation(res, BOT_FACET_L_FISH);
		applyOperation(res, U, DOUBL);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case D_EYES: {
		setFPurp(HS_FORM_YLW_LYR_D_EYES);
		applyOperation(res, BOT_FACET_R_FISH);
		applyOperation(res, BOT_FACET_R_FISH);
		break;
	}
	case HELI: {
		setFPurp(HS_FORM_YLW_LYR_HELI);
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