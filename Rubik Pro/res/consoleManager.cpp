#include "consoleManager.h"

// ������ ��� ��������� ������������ ������ ������������ Color ����� ������, ������� ������������ � �������.
// ������ �������� ������� �����. ������ ����� � Color
int colorDepends[6] = { 15, 6, 2, 4, 1, 14 };

using namespace std;

void dispEdges(const Color*** edg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���� ������� �����
	for (int j = 2; j >=0; j--) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // ����� ����� ���� ������� �� ������
		cout << "        "; // 8 ��������
		for (int k = 2; k >=0; k--) { // k ����������� ������, ��� ����� �������������� ����� ������
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[2][j][k]] << 4) | 0)); // ������ ������ ���� ����
			cout << "  "; // ������ ��� ������� � ������ �����
		}
		cout << endl;		
	}
	cout << endl;

	// ��� ����� ����������
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

	// ������ ����� �����
	for (int j = 0; j < 3; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "        "; // 8 spaces
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[4][j][k]] << 4) | 0));
			cout << "  ";
		}
		cout << endl;
	}

	// ������ �����
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

// ���������� � ������� ��������� ������, � ��������� ��������� ��������
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