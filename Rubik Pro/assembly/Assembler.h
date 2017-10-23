#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "..\res\Formula.h"
#include <assert.h>
#include "formulasLib.h"


//Класс, отвечающий за процесс сборки. В нем производится анализ модели и подбираются алгоритмы, необходимые на текущем этапе сборки
class Assembler {
	//Ссылка на модель кубика, с которым сейчас производится работа
	Cube & _cube;
	//Ссылка на временную модель куба, дублирующую текущий, но на которую сразу применяются формулы из всех функций сборки
	Cube _liveCube;
	//Класс анализатор
	Analyser * _analyser;

	// +++++++++++++++ Приватные функции +++++++++++++++++++
	// Найти, на какой грани находится цвет
	int findMidColor(Color color, Cube & cube);
	// Найти самый эффективный поворот для перестановки элемента с одной позиции в другую перпендикулярно оси Y
	Dir findOptimalYRot(int src, int tgt, ElementLocLayer layer);
	// Найти самый эффективный поворот для перестановки элемента с одной позиции в другую перпендикулярно оси Y
	Dir findOptimalYRot(ElementLocSide& src, ElementLocSide& tgt, ElementLocLayer layer);
	// Найти самый эффективный поворот для перестановки элемента с одной позиции в другую перпендикулярно оси Y
	Dir findOptimalYRot(ElementLocSide & src, int tgt, ElementLocLayer layer);
	// Найти, на какой стороне по расширенной системе должен в итоге стоять угловой элемент
	ElementLocSide findCornAdvSide(Corner& corn);

	// Преобразует номер грани, на которой находится элемент, в расшир. позицию
	ElementLocSide sideToAdv(int side);
	// Преобразует расшир. позицию в номер грани, на которой находится элемент
	int advToSide(ElementLocSide side);

	// Записывает операцию в результат и сразу же применяет к _liveCube
	Operation applyOperation(FormulaStack & res, Operation & oper);
	// Оформляет и записывает операцию в результат и сразу же применяет к _liveCube
	Operation applyOperation(FormulaStack & res, Move mov, Dir dir);
	// Записывает все операции массива в результат и сразу же применяет к _liveCube
	Operation applyOperation(FormulaStack & res, const vector<pair<Move, int>>);
	// Выставить кубик по верхнему и переднему цвету
	void allign(FormulaStack & res, Color colorOnTop, Color colorOnFront);
	// Выставить указанный кубик по верхнему и переднему цвету (без записи в стэк формул)
	//void allign(Color colorOnTop, Color colorOnFront, Cube& cube);

public:
	Assembler(Cube & c);
	~Assembler();
	
	void refresh();
	void allignCube(FormulaStack &, Color colorOnTop, Color colorOnFront);
	
	void doTopCross(FormulaStack &);
	void doTopLayer(FormulaStack &);
	void doMidLayer(FormulaStack &);
	void doBotCross(FormulaStack &);
	void doBotFacet(FormulaStack &);
	void doBotCorns(FormulaStack &);
	void doBotEdges(FormulaStack &);
};