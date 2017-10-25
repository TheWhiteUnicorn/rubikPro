#include "readinessAuditor.h"

readinessAuditor::readinessAuditor(Cube * cube, Assembler * assembler) : _cube(cube), assembler(assembler) {}


readinessAuditor::~readinessAuditor() {}

bool readinessAuditor::topCross() {
	Cube tmp(*_cube);
	tmp.rotate(assembler->findAllignmentOperation(WHITE, tmp));

	return false;
}

bool readinessAuditor::topLayer() {
	return false;
}

bool readinessAuditor::midLayer() {
	return false;
}

bool readinessAuditor::botCross() {
	return false;
}

bool readinessAuditor::botFacet() {
	return false;
}

bool readinessAuditor::botCorns() {
	return false;
}

bool readinessAuditor::cubeReady() {
	return false;
}

