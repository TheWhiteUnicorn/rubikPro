#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

void dispEdges() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "Hello world";
}