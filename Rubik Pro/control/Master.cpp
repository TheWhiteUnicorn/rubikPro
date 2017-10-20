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

	int iteration = 0;
	while (true) {
		_cube.trick(20);
		cout << "++++++++++++Tricked++++++++++++" << endl;
		dispEdges(_cube.get_edges());
		
		FormulaStack stack;

		_assembler.refresh();

		_assembler.allignCube(stack, WHITE, BLUE);
		applyAllFormulas(stack);
		
		cout << "TopCoross" << endl;
		_assembler.doTopCross(stack);
		applyAllFormulas(stack);
		
		cout << "TopLayer" << endl;
		_assembler.doTopLayer(stack);
		applyAllFormulas(stack);

		cout << "MidLayer" << endl;
		_assembler.doMidLayer(stack);
		applyAllFormulas(stack);

		cout << "BotCross" << endl;
		_assembler.doBotCross(stack);
		applyAllFormulas(stack);

		cout << "BotFacet" << endl;
		_assembler.doBotFacet(stack);
		applyAllFormulas(stack);

		iteration++;
	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}