#include <iostream>
#include "interface\MyForm.h"
#include "cube\Cube.h"
#include "res\consoleManager.h"

using namespace std;

int main() {
	std::cout << "Starting Rubik Pro beta..." << std::endl;
	//cout << "Testing testing" << endl;
	//startForm()
	
	Cube cube();

	dispEdges();

	system("pause");
	return 0;
}