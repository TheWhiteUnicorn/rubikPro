#include <iostream>
//#include "interface\MyForm.h"
#include "cube\Cube.h"
#include "res\consoleManager.h"
//#include "cv\Camera.h"

using namespace std;

int main() {
	std::cout << "Starting Rubik Pro beta..." << std::endl;
	//cout << "Testing testing" << endl;
	//startForm()

	Cube* cube = new Cube();
	int mov = -1;
	int dir = -1;
	while (true) {
		std::cout << "Starting Rubik Pro beta..." << std::endl;
		cout << "Rotation performed: " << mov << " " << dir << endl;

		dispEdges(cube->get_edges());

		cout << "Move: ";
		cin >> mov >> dir;
		if (dir == -1) break;
		if (dir == -2) cube->reset();
		cube->rotate(mov, dir);

		system("cls");
	}
	system("pause");
	return 0;
}