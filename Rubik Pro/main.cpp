//Монитор утечек памяти
#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif


#define NO_SRAND_BY_TIME

#include <iostream>
#include "interface\MyForm.h"
#include "control\Master.h"
#include "cv\InitialRecogniser.h"
//#include "cv\RubikState.h"


using namespace std;

int main() {
	Master master;
	
	//master.freeMode();
	master.readEdges();

	return 0;
}