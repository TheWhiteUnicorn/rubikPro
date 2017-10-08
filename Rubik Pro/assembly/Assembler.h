#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"

//Класс, отвечающий за процесс сборки. В нем производится анализ модели и подбираются алгоритмы, необходимые на текущем этапе сборки
class Assembler {
	//Ссылка на модель кубика, с которым сейчас производится работа
	Cube & _cube;
	//Класс анализатор
	Analyser * _analyser;

public:
	Assembler(Cube & c);
	~Assembler();
	
	void doTopCross();
};

