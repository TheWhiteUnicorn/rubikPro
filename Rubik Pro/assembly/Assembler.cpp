#include <cassert>
#include "Assembler.h"
#include "..\control\Master.h"

Assembler::Assembler(Cube & c) : _cube(c), _liveCube(c){
	_analyser = new Analyser(_liveCube);
	prepareFormulasForStandartAssembly(formLib);
}

Assembler::~Assembler() {
	delete _analyser;
}

void Assembler::allignCube(FormulaStack & res, Color colorOnTop, Color colorOnFront) {
	_liveCube = _cube;
	allign(res, colorOnTop, colorOnFront);
}

void Assembler::refresh() {
	_analyser->refresh();
}