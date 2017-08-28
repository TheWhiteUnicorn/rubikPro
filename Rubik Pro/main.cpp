#include <iostream>
#include "interface\MyForm.h"
#include "cube\Cube.h"
#include "res\consoleManager.h"
#include "cv\Camera.h"

using namespace std;

void cubeDemo(Cube*);

int main() {
	cout << "Starting Rubik Pro beta..." << endl;

	Cube * cube = new Cube();

	cubeDemo(cube);

	system("pause");
	return 0;
}

// Показывает в консоли развертку кубика, и позволяет совершать повороты
void cubeDemo(Cube * cube) {
	int mov = -1;
	int dir = -1;
	while (true) {
		std::cout << "Rubik Pro beta" << std::endl;
		cout << "Rotation performed: " << mov << " " << dir << endl;

		dispEdges(cube->get_edges());

		cout << "Move: ";
		cin >> mov >> dir;
		if (dir == -1) return;
		if (dir == -2) cube->reset();
		cube->rotate(mov, dir);

		system("cls");
	}
}