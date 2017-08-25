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

#define invD(dir) dir == 2 ? dir : Dir(1 - int(dir))

void Cube::rotate(Move move, Dir dir) {
	switch (move)
	{
	case F:
		sideRotY(0, dir);
		rot(0, dir);
		break;
	case R:
		sideRotX(0, dir);
		rot(3, dir);
		break;
	case L:
		sideRotX(2, invD(dir));
		rot(1, dir);
		break;
	case U:
		sideRotZ(2, dir);
		rot(2, dir);
		break;
	case D:
		sideRotZ(0, invD(dir));
		rot(4, dir);
		break;
	case B:
		sideRotY(2, invD(dir));
		rot(5, dir);
		break;
	case M:
		sideRotX(1, invD(dir));
		break;
	case S:
		sideRotY(1, invD(dir));
		break;
	case E:
		sideRotZ(1, dir);
		break;
	case Fw:
		sideRotY(0, dir);
		sideRotY(1, dir);
		rot(0, dir);
		break;
	case Rw:
		sideRotX(0, dir);
		sideRotX(1, dir);
		rot(3, dir);
		break;
	case Lw:
		sideRotX(2, invD(dir));
		sideRotX(1, invD(dir));
		rot(1, dir);
		break;
	case Uw:
		sideRotZ(2, dir);
		sideRotZ(1, dir);
		rot(2, dir);
		break;
	case Dw:
		sideRotZ(0, invD(dir));
		sideRotZ(1, invD(dir));
		rot(4, dir);
		break;
	case Bw:
		sideRotY(2, invD(dir));
		sideRotY(1, invD(dir));
		rot(5, dir);
		break;
	case x:
		sideRotX(0, dir);
		sideRotX(1, dir);
		sideRotX(2, dir);
		rot(3, dir);
		rot(1, invD(dir));
		break;
	case y:
		sideRotZ(0, dir);
		sideRotZ(1, dir);
		sideRotZ(2, dir);
		rot(2, dir);
		rot(4, invD(dir));
		break;
	case z:
		sideRotY(0, dir);
		sideRotY(1, dir);
		sideRotY(2, dir);
		rot(0, dir);
		rot(5, invD(dir));
		break;
	default:
		break;
	}
}

void Cube::rotate(int move, int dir) {
	if (move >= 0 && move <= 17 && dir >= 0 && dir <= 2) {
		this->rotate(Move(move), Dir(dir));
	}
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

