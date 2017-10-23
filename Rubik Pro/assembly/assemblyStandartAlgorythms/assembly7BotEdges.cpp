#include "..\Assembler.h"

void Assembler::doBotEdges(FormulaStack & res) {
	_liveCube = _cube;
	allign(res, YELLOW, BLUE);

	Dir allignRotDirection;
	BotEdgesSituation situation = _analyser->findBotEdgesSituation(allignRotDirection);
	applyOperation(res, y, allignRotDirection);

	switch (situation)
	{
	case BOT_E_SHIFT_CKW: {
		applyOperation(res, BOT_EDGES_TRIANGLE_CKW);
		break;
	}
	case BOT_E_SHIFT_ACKW: {
		applyOperation(res, BOT_EDGES_TRIANGLE_ACKW);
		break;
	}
	case BOT_E_SLAIGH: {
		applyOperation(res, BOT_EDGES_TRIANGLE_ACKW);
		applyOperation(res, U, ACKW);
		applyOperation(res, BOT_EDGES_TRIANGLE_ACKW);
		applyOperation(res, U, CKW);
		break;
	}
	case BOT_E_CROSS:
	{
		applyOperation(res, BOT_EDGES_TRIANGLE_ACKW);
		applyOperation(res, U, CKW);
		applyOperation(res, BOT_EDGES_TRIANGLE_ACKW);
		applyOperation(res, U, ACKW);
		break;
	}
	case BOT_E_DONE:
		break;
	default:
		throw 1;
	}
}