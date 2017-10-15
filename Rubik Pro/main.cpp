#include <iostream>
#include "interface\MyForm.h"
#include "control\Master.h"
#include "cv\Recognition.h"


using namespace std;

int main() {
	Master master;
	//master.freeMode();
	master.readEdges();
	CubeCV();
	//system("pause");
	return 0;
}
