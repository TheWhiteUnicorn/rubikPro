#pragma once
#include "..\..\cube\Cube.h"
#include "..\..\cube\Element.h"
#include <map>
#include <vector>

using namespace std;

const int NUM_OF_WHITES = 4; //Имеется в виду количество элементов одного класса (4 - угловых и 4 - ребра)
const int NUM_OF_MID_EDGES = 4;
const int NUM_OF_YELLOWS = 4;


#define _edgeVector vector<Edge*>
#define _cornVector vector<Corner*>

// Ситуации, которые могут возникать на нажнем кресте (палка, галка, точка, крест)
enum YellowCrossSituation { STICK, DAW, DOT, CROSS };

// Ситуации, которые могут возникать на нижнем слое (левая рыбка, правая рыбка, глаза, уши, восьмерка, двойные глаза, вертолет, сторона собрана)
enum YellowLayerSituation {L_FISH, R_FISH, EYES, EARS, EIGHT, D_EYES, HELI, LAYER_DONE};

// Ситуации, которые могут возникать c вершинами нижнего слоя
enum BotCornsSituation { BOT_C_CYCLIC_SHIFT_CKW, BOT_C_CYCLIC_SHIFT_ACKW, BOT_C_DIAGONAL_SWITCH, BOT_C_DONE };

// Ситуации, которые могут возникать c ребрами нижнего слоя ()
enum BotEdgesSituation {BOT_E_SHIFT_CKW, BOT_E_SHIFT_ACKW, BOT_E_SLAIGH, BOT_E_CROSS, BOT_E_DONE};

class Analyser {
public:
	Analyser(Cube & cube);
	~Analyser();

	void set_cube(Cube& cub) { this->_cube = cub; }

	void refresh();

	// Найти все грани, на которых есть белая наклейка
	_edgeVector& findWhitesEdge();
	// Найти все уголки, на которых есть белая наклейка
	_cornVector& findWhitesCorn();
	// Найти все грани, на которых нет ни белой ни желтой наклейки
	_edgeVector& findMidEdge();
	// Находит ситуации, которые могут возникать на нажнем кресте (палка, галка, точка, крест). Предполагается, что желтая грань расположена сверху
	YellowCrossSituation findYellowCrossSituations(Dir&);
	// Находит ситуации, которые могут возникать на нижнем слое (см. объявление перечисления). Предполагается, что желтая грань расположена сверху
	YellowLayerSituation findYellowLayerSituations(Dir&);
	// Анализатор конфигурации нижних угловых элементов
	// Через параметр возвращает цвет, который должен быть сверху при выравнивании
	BotCornsSituation findBotCornsConfig(Color&);
	// Находит ситуации, которые могут возникать c ребрами нижнего слоя
	BotEdgesSituation findBotEdgesSituation(Dir& res);

private:
	Cube & _cube;

	_edgeVector _whitesEdge;
	_cornVector _whitesCorn;
	_edgeVector _midEdges;



	// ++++++++++ Вспомогательные констркции ++++++++++++++++

	// Восемь уголков - карта
	int _cornersMap[8][3][3]{ // ЗДЕСЬ ВСЕ ОЧЕНЬ ХОРОШО И ПРАВИЛЬНО :3
		{ { 2, 2, 0 },{ 5, 2, 2 },{ 3, 2, 2 } }, // Верхний слой
		{ { 2, 0, 0 },{ 3, 0, 2 },{ 0, 0, 2 } },
		{ { 2, 0, 2 },{ 0, 0, 0 },{ 1, 0, 0 } },
		{ { 2, 2, 2 },{ 1, 2, 0 },{ 5, 2, 0 } },

		{ { 4, 2, 2 },{ 3, 2, 0 },{ 5, 0, 2 } }, // Нижний слой
		{ { 4, 0, 2 },{ 0, 2, 2 },{ 3, 0, 0 } },
		{ { 4, 0, 0 },{ 1, 0, 2 },{ 0, 2, 0 } },
		{ { 4, 2, 0 },{ 5, 0, 0 },{ 1, 2, 2 } },
	};

	// 12 граней - карта
	int _edgesMap[12][2][3]{
		{ { 2, 2, 1 },{ 5, 2, 1 } }, // Верхний слой 
		{ { 2, 1, 0 },{ 3, 1, 2 } },
		{ { 2, 0, 1 },{ 0, 0, 1 } },
		{ { 2, 1, 2 },{ 1, 1, 0 } },

		{ { 5, 1, 2 },{ 3, 2, 1 } }, // Средний слой
		{ { 3, 0, 1 },{ 0, 1, 2 } },
		{ { 0, 1, 0 },{ 1, 0, 1 } },
		{ { 1, 2, 1 },{ 5, 1, 0 } },

		{ { 4, 2, 1 },{ 5, 0, 1 } }, // Нижний слой
		{ { 4, 1, 2 },{ 3, 1, 0 } },
		{ { 4, 0, 1 },{ 0, 2, 1 } },
		{ { 4, 1, 0 },{ 1, 1, 2 } },
	};

	// Карта сопоставления главного и дополнительного цвета граней среднего слоя
	map<Color, Color>  sideEdgesAssoc { { ORANGE, GREEN },{ GREEN, RED }, {RED, BLUE}, {BLUE, ORANGE} };
};