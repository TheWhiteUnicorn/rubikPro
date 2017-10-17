#include "Master.h"
#include "..\cv\InitialRecogniser.h"

void Master::applyAllFormulas(FormulaStack& formStack) {
	while (formStack.doFirstUnperfOper(_cube)) {}
	formStack.clear();
}

Master::Master(){

}

Master::~Master(){
	
}

void Master::readEdges() {
	InitialRecogniser initRec;
	initRec.CubeCV();
	for (;;)
	{
		initRec.showFrame();
		char c = cvWaitKey(33);
		if (c == 27)  // нажата ESC

			break;
	}

	initRec.fillSquares(0);
}

void Master::standartAssembly(){


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
	}
}

void Master::freeMode(){
	cubeDemo(_cube);
}

