#include "Master.h"

void Master::applyAllFormulas(FormulaStack& formStack) {
	while (formStack.doFirstUnperfOper(_cube)) {}
	formStack.clear();
}

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
		
		FormulaStack stack;
		stack.pushBack(Operation(F, CKW));
		stack.pushBack(Operation(F, ACKW));
		applyAllFormulas(stack);

		//Formula formula;
		_assembler.refresh();

		_assembler.allignCube(stack, WHITE, BLUE);
		applyAllFormulas(stack);
		
		cout << "TopCoross" << endl;
		_assembler.doTopCross(stack);
		applyAllFormulas(stack);
		
		cout << "TopLayer" << endl;
		_assembler.allignCube(stack, YELLOW, GREEN);
		_assembler.doTopLayer(stack);
		applyAllFormulas(stack);

	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}

