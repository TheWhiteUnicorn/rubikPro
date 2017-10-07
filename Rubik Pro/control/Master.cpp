#include "Master.h"

Master::Master(){
	
}

Master::~Master(){
	
}

void Master::standartAssembly(){
	_cube.trick(20);
	dispEdges(_cube.get_edges());

}

void Master::freeMode(){
	cubeDemo(_cube);
}

