#include <iostream>
#include "interface\MyForm.h"
#include "cv\Camera.h"
#include "control\Master.h"

using namespace std;

int main() {
	Master master;
	//master.freeMode();
	master.standartAssembly();
	system("pause");
	return 0;
}

