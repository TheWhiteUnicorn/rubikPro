#include "Master.h"

Master::Master(){

}

Master::~Master(){
	
}

void Master::standartAssembly(){
	while (true) {
		_cube.trick(20);
		dispEdges(_cube.get_edges());
		Formula formula;
		_assembler.allignCube(formula);
		_cube.applyFormula(formula);
		//_cube.rotate(formula.get_sequence().front());
		dispEdges(_cube.get_edges());
		//_assembler.doTopCross(formula);
	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}

