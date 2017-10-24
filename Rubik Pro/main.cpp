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

	//master.getState().launchCapture();

	return 0;
}
