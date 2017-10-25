#include "InitialRecogniser.h"

void fillReferenceColors(Scalar* refs, RubickColors& cols) {
	for (int i = 0; i < 6; i++) {
		refs[i] = cols.colors[i][1][1];
	}
}

Color InitialRecogniser::classifyColor(Scalar rawColor) {
	Color answ = WHITE;
	double minDelta = 800; // 255*3 с небольшим округлением

	for (int i = 0; i < 6; i++) {
		double redDelta = abs(referenceColors[i][2] - rawColor[2]);
		double greenDelta = abs(referenceColors[i][1] - rawColor[1]);
		double blueDelta = abs(referenceColors[i][0] - rawColor[0]);

		double totalDelta = redDelta + greenDelta + blueDelta; 

		if (totalDelta < minDelta) {
			minDelta = totalDelta;
			answ = Color(i);
		}
		
	}
	return answ;
}

void InitialRecogniser::initialModelFilling(CubeColorsTable& res) {
	fillReferenceColors(referenceColors, rawColors);

	for (int i = 0; i < 6; i++) {
		semanticTransformationOfColors(res.facets[i], i);
	}
}

bool InitialRecogniser::checkRotCorrectness(Cube & cub, Operation & oper) {
	Cube tmp(cub);
	tmp.rotate(oper);
	
	saveEdgeColorsBuffer(0);

	FacetColorsMatrix realEdge;

	semanticTransformationOfColors(realEdge, 0);

	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			if (realEdge.colors[j][k] != tmp.get_edges()[0][j][k])
				return false;
		}
	}

	return true;
}

void InitialRecogniser::semanticTransformationOfColors(FacetColorsMatrix& res, int facet) {
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			Scalar clr = rawColors.colors[facet][j][k];
			res.colors[j][k] = classifyColor(clr);
		}
	}
}