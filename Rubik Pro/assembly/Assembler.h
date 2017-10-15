#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "..\res\Formula.h"


//Класс, отвечающий за процесс сборки. В нем производится анализ модели и подбираются алгоритмы, необходимые на текущем этапе сборки
class Assembler {
	//Ссылка на модель кубика, с которым сейчас производится работа
	Cube & _cube;
	//Ссылка на временную модель куба, дублирующую текущий, но на которую сразу применяются формулы из всех функций сборки
	Cube _liveCube;
	//Класс анализатор
	Analyser * _analyser;

	// Приватные функции
	// Найти, на какой грани находится цвет
	int findMidColor(Color color, Cube & cube);
	// Найти самый эффективный поворот для перестановки элемента с одной позиции в другую
	Dir findOptimalYRot(int src, int tgt, ElementLocLayer layer);
	Dir findOptimalYRot(ElementLocSide& src, ElementLocSide& tgt, ElementLocLayer layer);

	// Преобразует номер грани, на которой находится элемент, в расшир. позицию
	ElementLocSide sideCoordOfEdgeToAdvancedPos(int side);
	// Преобразует расшир. позицию в номер грани, на которой находится элемент
	int AdvancedPosToSideCoordOfEdge(ElementLocSide side);

	// Записывает операцию в результат и сразу же применяет к _liveCube
	void applyOperation(Formula & res, Operation & oper);
	// Оформляет и записывает операцию в результат и сразу же применяет к _liveCube
	void applyOperation(Formula & res, Move mov, Dir dir);
	// 
	void allign(Formula &, Color colorOnTop, Color colorOnFront);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void refresh();
	void allignCube(Formula &, Color colorOnTop, Color colorOnFront);
	void doTopCross(Formula &);
};

