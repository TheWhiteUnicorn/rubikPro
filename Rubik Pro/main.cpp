#include <iostream>
#include "interface\MyForm.h"
#include "control\Master.h"
#include "cv\InitialRecogniser.h"


using namespace std;

int main() {
	Master master;
	//master.freeMode();
	master.readEdges();
	//system("pause");
	return 0;
}
