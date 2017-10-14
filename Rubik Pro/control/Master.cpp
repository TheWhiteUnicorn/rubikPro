#include "Master.h"

Master::Master(){

}

Master::~Master(){
	
}

void Master::standartAssembly(){
	while (true) {
		_cube.trick(20);
		cout << "+++++++++++Tricked++++++++++++" << endl;
		dispEdges(_cube.get_edges());
		Formula formula;
		_assembler.allignCube(formula, WHITE, BLUE);
		_cube.applyFormula(formula);

		_assembler.doTopCross(formula);
	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}

