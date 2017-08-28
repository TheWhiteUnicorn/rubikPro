#pragma once

	// Перечисление цветов наклеек, соответствует конфигурации цветов на гранях в собранном кубике
	enum color { WHITE, ORANGE, GREEN, RED, BLUE, YELLOW };

	// Направление вращения. Соответственно, по часовой, против и двойной поворот
	enum Dir { CKW, ACKW, DOUBL };

	// Перечисление всех возможных движений кубика
	enum Move { F, R, L, U, D, B, M, S, E, Fw, Rw, Lw, Uw, Dw, Bw, x, y, z };