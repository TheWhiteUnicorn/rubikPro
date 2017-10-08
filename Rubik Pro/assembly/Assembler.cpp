#include "Assembler.h"




Assembler::Assembler(Cube & c) : _cube(c) {
	_analyser = new Analyser(_cube);
}

Assembler::~Assembler() {
	delete _analyser;
}

void Assembler::doTopCross() {

}
