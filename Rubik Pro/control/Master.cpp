#include "Master.h"

Master::Master(){

}

Master::~Master(){
	
}

void Master::standartAssembly(){


	while (true) {
		_cube.trick(20);
		cout << "++++++++++++Tricked++++++++++++" << endl;
		dispEdges(_cube.get_edges());


		/*_cube.rotate(2, 2);
		_cube.rotate(3, 1);*/
		_cube.rotate(4, 2);

		Formula formula;
		_assembler.refresh();

		_assembler.allignCube(formula, WHITE, BLUE);
		_cube.applyFormula(formula);
		formula.clear();

		_assembler.doTopCross(formula);
	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}

