#include "Master.h"

Master::Master(){

}

Master::~Master(){
	
}

void Master::readEdges() {
	InitialRecogniser initRec;
	
}

void Master::standartAssembly(){
	_cube.trick(20);
	dispEdges(_cube.get_edges());
	Formula formula;
	_assembler.doTopCross(formula);
}

void Master::freeMode(){
	cubeDemo(_cube);
}

