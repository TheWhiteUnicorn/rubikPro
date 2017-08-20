#include "consoleManager.h"

int colorDepends[6] = { 15, 6, 2, 4, 1, 14 };

using namespace std;

void dispEdges(const color*** edg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	for (int j = 0; j < 3; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "        "; // 8 spaces
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[0][j][k]] << 4) | 0));
			cout << "  ";
		}
		cout << endl;		
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 1; i < 4; i++) {
			for (int k = 0; k < 3; k++) {
				SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[i][j][k]] << 4) | 0));
				cout << "  ";
			}
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
			cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); // set to default
		cout << "        "; // 8 spaces
		for (int k = 0; k < 3; k++) {
			SetConsoleTextAttribute(hConsole, (WORD)((colorDepends[edg[4][j][k]] << 4) | 0));
			cout << "  ";
		}
		cout << endl;
	}
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
}