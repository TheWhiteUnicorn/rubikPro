#include "Cube.h"

void Cube::swH (int row, int edge1, int edge2) {
	for (int k = 0; k < 3; k++) {
		color t = edges[edge1][row][k];
		edges[edge1][row][k] = edges[edge2][row][k];
		edges[edge2][row][k] = t;
	}
}

void Cube::swV(int col, int edge1, int edge2) {
	for (int j = 0; j < 3; j++) {
		color t = edges[edge1][j][col];
		edges[edge1][j][col] = edges[edge2][j][col];
		edges[edge2][j][col] = t;
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