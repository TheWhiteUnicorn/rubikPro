#include "InitialRecogniser.h"




void InitialRecogniser::fillSquares(int edgeShown /* Это номер грани, которую показывают, вызывая эту функцию, поле массива с соотв. гранью и нужно отображать*/) {
	//RubickColors *color = new RubickColors();

	Mat image;
	vector<vector<Point>> squares;

	while (squares.size() != 9) {

		*cap >> image;

		Mat temp_frame;
		image.copyTo(temp_frame);
		findSquares(temp_frame, squares);
		drawSquares(image, squares);


		int j = 2, k = 2;
		if (squares.size() != 9)
			continue;

			for (size_t i = 0; i < squares.size(); i++)
			{
				const Point* p = &squares[i][0];
				int n = (int)squares[i].size();
				int shift = 0;

				// Ограничивающие прямоугольники
				Rect r = boundingRect(Mat(squares[i]));
				r.x = r.x + r.width / 4;
				r.y = r.y + r.height / 4;
				r.width = r.width / 2;
				r.height = r.height / 2;

				Mat roiImage = image(box);

				Mat roi = roiImage(r);

				Scalar temp_color = mean(roi);

				rawColors.colors[edgeShown][j][k] = temp_color;


				polylines(roiImage, &p, &n, 1, true, temp_color, 2, LINE_AA, shift);

				Point center(r.x + r.width / 2, r.y + r.height / 2);

				ellipse(roiImage, center, Size(r.width / 2, r.height / 2), 0, 0, 360, temp_color, 2, LINE_AA);

				k--;
				if (k == -1) {
					k = 2;
					j--;
				}

			}
		

	}
}