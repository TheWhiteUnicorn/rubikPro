#include "Analyser.h"

Analyser::Analyser(Cube & cube) : _cube(cube) {}

Analyser::~Analyser() {}

const Element * Analyser::findWhites() {
	int addedCorners = 0;
	// »щем белые уголки
	for (int i = 0, int side = 0, int layer = 0; i < 8; i++, side++) {
		if (side == 4) {
			side = 0;
			layer = 2;
		}

		Color prim  = _cube.get_edges()[_cornersMap[i][0][0]][_cornersMap[i][0][1]][_cornersMap[i][0][2]];
		Color side1 = _cube.get_edges()[_cornersMap[i][1][0]][_cornersMap[i][1][1]][_cornersMap[i][1][2]];
		Color side2 = _cube.get_edges()[_cornersMap[i][2][0]][_cornersMap[i][2][1]][_cornersMap[i][2][2]];
		if (prim == WHITE) {
			_whites[addedCorners] = new Corner();
			
			
		}
	}
}


