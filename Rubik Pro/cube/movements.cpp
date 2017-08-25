#include "Cube.h"

// Для случаев, когда одна грань повернута относительно другой
#define switchCols(x, y) for (int k = 0; k < 3; k++) {	\
		color t = x;									\
		x = y;			\
		y = t;			\
}

// Обмен линий местами (горизонтальный)
#define swH(row1, row2, e1, e2) for (int k = 0; k < 3; k++) {	\
		color t = edges[e1][row1][k];						\
		edges[e1][row1][k] = edges[e2][row2][k];			\
		edges[e2][row2][k] = t;								\
	}

// Обмен линий местами (вертикальный)
#define swV(col1, col2, e1, e2) for (int j = 0; j < 3; j++) {	\
		color t = edges[e1][j][col1];						\
		edges[e1][j][col1] = edges[e2][j][col2];			\
		edges[e2][j][col2] = t;								\
	}

// Поворот слоя, параллельного оси Х
// dir: 0 - по часовой, 1 - против часовой, 2 - двойной поворот
void Cube::sideRotX (int col, Dir dir) {
	col = 2 - col;
	switch (dir)
	{
	case 0: {
		swV(col, col, 0, 4)
		swV(col, col, 4, 5)
		switchCols(edges[5][k][col], edges[2][2 - k][2 - col])
		break;
		
	}
	case 1: {
		switchCols(edges[5][k][col], edges[2][2 - k][2 - col])
		swV(col, col, 4, 5)
		swV(col, col, 0, 4)
		break;
	}
	case 2: {
		switchCols(edges[4][k][col], edges[2][2 - k][2 - col])
		swV(col, col, 0, 5)
		break;
	}
	default:
		break;
	}
}

// Поворот слоя, параллельного оси Y
void Cube::sideRotY(int row, Dir dir) {
	switch (dir)
	{
	case 0: {
		swH(row, row, 3, 4)
		swH(row, row, 3, 2)
		swH(row, row, 2, 1)
		break;
	}
	case 1: {
		swH(row, row, 2, 1)
		swH(row, row, 3, 2)
		swH(row, row, 3, 4)
		break;
	}
	case 2: {
		swH(row, row, 3, 1)
		swH(row, row, 4, 2)
		break;
	}
	default:
		break;
	}
}

// Поворот слоя, параллельного оси Z
void Cube::sideRotZ(int col, Dir dir) {
	switch (dir)
	{
	case 0: {
		switchCols(edges[5][col][2 - k], edges[1][2 - k][2 - col])
		switchCols(edges[1][2 - k][2 - col], edges[0][2 - col][k])
		switchCols(edges[0][2 - col][k], edges[3][k][col])
		break;
	}
	case 1: {
		switchCols(edges[0][2 - col][k], edges[3][k][col])
		switchCols(edges[1][2 - k][2 - col], edges[0][2 - col][k])
		switchCols(edges[5][col][2 - k], edges[1][2 - k][2 - col])
		break;
	}
	case 2: {
		switchCols(edges[1][k][2 - col], edges[3][2 - k][col])
		switchCols(edges[0][2 - col][k], edges[5][col][2 - k])
		break;
	}
	default:
		break;
	}
}

void Cube::rot(int edge, Dir dir) {//CKW - по часовой, если true
	color t[3][3];
	
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			t[j][k] = edges[edge][j][k];
		}
	}

	switch (dir)
	{
	case 0: {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				edges[edge][j][k] = t[2 - k][j];
			}
		}
		break;
	}
	case 1: {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				edges[edge][j][k] = t[k][2 - j];
			}
		}
		break;
	}
	case 2: {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				edges[edge][k][j] = t[2 - k][2 - j];
			}
		}
		break;
	}
	default:
		break;
	}
}