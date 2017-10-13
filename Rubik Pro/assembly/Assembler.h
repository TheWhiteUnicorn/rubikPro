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

	/// Приватные функции
	int findMidColor(Color color, Cube & cube);
	Dir findOptimalYRot(int src, int tgt);
	int sideCoordOfEdgeToAdvancedPos(int side);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void allignCube(Formula &);
	void doTopCross(Formula &);
};

