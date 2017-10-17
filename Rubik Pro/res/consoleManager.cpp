#include "consoleManager.h"

// Массив для установки соответствия цветов перечисления Color кодам цветов, которые используются в консоли.
// Индекс элемента массива соотв. номеру цвета в Color
int colorDepends[6] = { 15, 6, 2, 4, 1, 14 };

using namespace std;

void dispEdges(const Color*** edg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Одна верхняя грань
	for (int j = 2; j >=0; j--) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // Сброс цвета фона консоли на черный
		cout << "        "; // 8 пробелов
		for (int k = 2; k >=0; k--) { // k уменьшается потому, что грань отрисовывается задом наперёд
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[2][j][k]] << 4) | 0)); // ставим нужный цвет фона
			cout << "  "; // ставим два пробела с нужным фоном
		}
		cout << endl;		
	}
	cout << endl;

	// Три грани посередине
	for (int j = 0; j < 3; j++) {
	
		for (int k = 2; k >= 0; k--) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[1][k][j]] << 4) | 0));
			cout << "  ";
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "  ";
		
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[0][j][k]] << 4) | 0));
			cout << "  ";
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "  ";

		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[3][k][2 - j]] << 4) | 0));
			cout << "  ";
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "  ";

		cout << endl;
	}
	cout << endl;

	// Вторая грань снизу
	for (int j = 0; j < 3; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "        "; // 8 spaces
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[4][j][k]] << 4) | 0));
			cout << "  ";
		}
		cout << endl;
	}

	// Нижняя грань
	cout << endl;
	for (int j = 0; j < 3; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "        "; // 8 spaces
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[5][j][k]] << 4) | 0));
			cout << "  ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
	cout << endl;
}

// Показывает в консоли развертку кубика, и позволяет совершать повороты
void cubeDemo(Cube& cube) {
	int mov = -1;
	int dir = -1;
	while (true) {
		std::cout << "Rubik Pro beta" << std::endl;
		cout << "Rotation performed: " << mov << " " << dir << endl;

		dispEdges(cube.get_edges());

		cout << "Move: ";
		cin >> mov >> dir;
		if (mov == -1) return;
		if (mov == -2) cube.reset();
		cube.rotate(mov, dir);

		system("cls");
	}
}