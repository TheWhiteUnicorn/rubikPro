#include <iostream>
#include "interface\MyForm.h"
#include "cube\Cube.h"
#include "res\consoleManager.h"
#include "cv\Camera.h"

using namespace std;

int main() {
	std::cout << "Starting Rubik Pro beta..." << std::endl;
	//cout << "Testing testing" << endl;
	//startForm()

	Cube* cube = new Cube();
	cube->rotate(TEST);
	dispEdges(cube->get_edges());

	system("pause");
	return 0;
}