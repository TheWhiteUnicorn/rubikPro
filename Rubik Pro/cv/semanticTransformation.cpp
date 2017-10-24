#include "InitialRecogniser.h"

void fillReferenceColors(Scalar* refs, RubickColors& cols) {
	for (int i = 0; i < 6; i++) {
		refs[i] = cols.colors[i][1][1];
	}
}

Color InitialRecogniser::classifyColor(Scalar rawColor) {
	Color answ = WHITE;
	int minDelta = 800; // 255*3 с небольшим округлением

	for (int i = 0; i < 6; i++) {
		int redDelta = abs(referenceColors[i][2] - rawColor[2]);
		int greenDelta = abs(referenceColors[i][1] - rawColor[1]);
		int blueDelta = abs(referenceColors[i][0] - rawColor[0]);

		int totalDelta = redDelta + greenDelta + blueDelta; {
			minDelta = totalDelta < minDelta ? totalDelta : minDelta;
			answ = Color(i);
		}
	}

	return answ;
}

void InitialRecogniser::initialModelFilling(Color *** res) {
	fillReferenceColors(referenceColors, rawColors);

	for (int i = 0; i < 6; i++) {
		semanticTransformationOfColors(res[i], i);
	}
}

void InitialRecogniser::semanticTransformationOfColors(Color ** res, int facet) {
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++)
			res[j][k] = classifyColor(rawColors.colors[facet][j][k]);
	}
}