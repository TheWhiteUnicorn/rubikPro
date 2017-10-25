#include "InitialRecogniser.h"


void InitialRecogniser::drawBoundingSquares(Mat & image) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			rectangle(image, squaresTopLeft(i, j), squaresBotRight(i, j), Scalar(0, 0, 255), 2);
		}
	}
}

void InitialRecogniser::saveEdgeColorsBuffer(int edge) {
}

void InitialRecogniser::gridRecognition(Mat& image) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vector<Point> boundingPointsPair = { squaresTopLeft(i, j), squaresBotRight(i, j) };
			Rect gridBox = boundingRect(boundingPointsPair);

			Mat roi = image(gridBox);

			//Mat roi = roiImage(gridBox);
			Scalar temp_color = mean(roi);

			curFacetBuffer[i][j] = temp_color;

			ellipse(image, SQUARES_COORDS[i][j], Size(20, 20), 0, 0, 360, temp_color, 2, LINE_AA);
		}
	}
}