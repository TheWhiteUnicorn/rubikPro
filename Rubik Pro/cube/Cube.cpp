#include "Cube.h"
#include "..\res\res.hpp"


Cube::Cube()
{
	initEdges();
	Cube::reset();
}


Cube::Cube(color(&edg)[6][3][3])
{
	initEdges();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = edg[i][j][k];
		}
	}
}


Cube::~Cube()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			delete[]edges[i][j];
		}
		delete[]edges[i];
	}
	delete[]edges;
}

const color *** Cube::get_edges() {
	return (const color ***)edges;
}

void Cube::reset() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = color(i);
		}
	}
}

void Cube::rotate(Move move) {
	swH(0, 1, 2);
	swV(1, 0, 3);
	swV(2, 0, 1);
	rot(0, false);
}

void Cube::initEdges() {
	this->edges = new color**[6];
	for (int i = 0; i < 6; i++) {
		edges[i] = new color*[3];
		for (int j = 0; j < 3; j++) {
			edges[i][j] = new color[3];
		}
	}
}

