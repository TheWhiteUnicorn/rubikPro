#include <iostream>
#include "interface\MyForm.h"
#include "control\Master.h"
#include "cv\Camera.h"


using namespace std;

int main() {
	Master master;
	master.freeMode();
	//CubeCV();
	system("pause");
	return 0;
}
