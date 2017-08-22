#include "Cube.h"

// Обмен линий местами (горизонтальный)
#define swH(row1, row2, e1, e2) for (int k = 0; k < 3; k++) {	\
		color t = edges[e1][row1][k];					\
		edges[e1][row1][k] = edges[e2][row2][k];			\
		edges[e2][row2][k] = t;							\
	}

// Обмен линий местами (вертикальный)
#define swV(col1, col2, e1, e2) for (int j = 0; j < 3; j++) {	\
		color t = edges[e1][j][col1];					\
		edges[e1][j][col1] = edges[e2][j][col2];			\
		edges[e2][j][col2] = t;							\
	}

// Поворот слоя, параллельного оси Х
// dir: 0 - по часовой, 1 - против часовой, 2 - двойной поворот
void Cube::sideRotX (int col, int dir) {
	switch (dir)
	{
	case 0: {
		swV(col, col, 0, 4);
		swV(col, col, 4, 5);
		swV(col, (2 - col), 5, 2);
		break;
		
	}
	case 1: {
		swV(col, col, 4, 0);
		swV(col, (2-col), 0, 2);
		swV((2 - col), col, 2, 5);
		break;
	}
	case 2: {
		swV((2-col), col, 2, 4);
		swV(col, col, 0, 5);
		break;
	}
	default:
		break;
	}
}

// Поворот слоя, параллельного оси Y
void Cube::sideRotY(int row, int dir) {
	
}

// Поворот слоя, параллельного оси Z
void Cube::sideRotZ(int col, int dir) {
	switch (dir)
	{
	case 0: {
		swV(col, col, 0, 4);
		swV(col, col, 4, 5);
		swV(col, (2 - col), 5, 2);
		break;

	}
	case 1: {
		swV(col, col, 4, 0);
		swV(col, (2 - col), 0, 2);
		swV((2 - col), col, 2, 5);
		break;
	}
	case 2: {
		swV((2 - col), col, 2, 4);
		swV(col, col, 0, 5);
		break;
	}
	default:
		break;
	}
}

void Cube::rot(int edge, bool CKW) {//CKW - по часовой, если true
	color t[3][3];
	
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			t[j][k] = edges[edge][j][k];
		}
	}

	if (CKW) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				edges[edge][j][k] = t[2 - k][j];
			}
		}
	}
	else {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				edges[edge][j][k] = t[k][2 - j];
			}
		}
	}
}