#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "Formula.h"


//Класс, отвечающий за процесс сборки. В нем производится анализ модели и подбираются алгоритмы, необходимые на текущем этапе сборки
class Assembler {
	//Ссылка на модель кубика, с которым сейчас производится работа
	Cube & _cube;
	//Класс анализатор
	Analyser * _analyser;

	/// Приватные функции
	int findMidColor(Color color);
	Operation findOptimalYRot(int src, int tgt);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void allignCube(Formula &);
	void doTopCross(Formula &);
};

