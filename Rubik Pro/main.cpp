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


using namespace std;

int main() {
	Master *master = new Master();
	//master->freeMode();
	master->standartAssembly();
	//CubeCV();
	delete master;
	//_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
