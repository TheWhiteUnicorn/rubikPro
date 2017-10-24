#include "Master.h"
#include "..\cv\InitialRecogniser.h"

Master::Master(){

}

Master::~Master(){
	
}

void Master::readEdges() {
	InitialRecogniser initRec;
	initRec.ready();
	for (;;)
	{
		initRec.showFrame();
		char c = cvWaitKey(33);
		if (c == 13)  // нажата Enter

			break;
	}

	initRec.fillSquares(0);
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

/*RubikState Master::getState() {
	return this->state;
}*/

