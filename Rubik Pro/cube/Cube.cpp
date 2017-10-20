#include "Cube.h"
#include <iostream>
#include <ctime>
#include "..\res\consoleManager.h"

#define invD(dir) dir == 2 ? dir : Dir(1 - int(dir))
const int NUM_OF_MOVEMENTS = 18, NUM_OF_DIRS = 3;

Cube::Cube()
{
	initEdges();
	Cube::reset();
}

Cube::Cube(Color(&edg)[6][3][3])
{
	initEdges();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = edg[i][j][k];
		}
	}
}

Cube::Cube(Cube & cub) { // Возможно, не работает. Протестировать
	initEdges();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = cub.get_edges()[i][j][k];
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

const Color *** Cube::get_edges() const {
	return (const Color ***)edges;
}

// Номер наклейки по развертке -> координаты по строке и столбцу
int coordsOfStickers[9][2]{
	{ 0,0 },
	{ 0,1 },
	{ 0,2 },
	{ 1,0 },
	{ 1,1 },
	{ 1,2 },
	{ 2,0 },
	{ 2,1 },
	{ 2,2 }
};

const Color Cube::get_color(int facet, int num) const{
	num--;
	return edges[facet][coordsOfStickers[num][0]][coordsOfStickers[num][1]];
}

void Cube::reset() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = Color(i);
		}
	}
}



void Cube::trick(int numOfOperations) {
	srand(time(0));
	for (int i = 0; i < numOfOperations; i++) {
		rotate(rand() % NUM_OF_MOVEMENTS, rand() % NUM_OF_DIRS);
	}
}

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

#ifdef DISP_ALL_MOVEMENTS
	cout << move << dir << endl;
	dispEdges((const Color ***)this->edges);
#endif // DISP_ALL_MOVEMENTS
}

void Cube::rotate(Operation op) {
	this->rotate(op.move, op.direction);
}

void Cube::rotate(int move, int dir) {
	if (move >= 0 && move <= 17 && dir >= 0 && dir <= 2) {
		this->rotate(Move(move), Dir(dir));
	}
}

void Cube::applyFormula(Formula & f) {
	for (auto i = f.get_sequence().begin(); i != f.get_sequence().end(); ++i) {
		rotate(*i);
	}
}

Cube & Cube::operator=(Cube & cub) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				edges[i][j][k] = cub.get_edges()[i][j][k];
		}
	}
	return *this;
}

void Cube::initEdges() {
	this->edges = new Color**[6];
	for (int i = 0; i < 6; i++) {
		edges[i] = new Color*[3];
		for (int j = 0; j < 3; j++) {
			edges[i][j] = new Color[3];
		}
	}
}

