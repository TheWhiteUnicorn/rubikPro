#pragma once

#include "..\cube\Cube.h"
#include "..\assembly\Assembler.h"
#include "..\res\consoleManager.h"

//Класс, контролирующий основной процесс работы приложения
class Master
{
	//Рабочая модель кубика
	Cube _cube;
	Assembler _assembler{_cube};

	void applyAllFormulas(FormulaStack& );
public:
	Master();
	~Master();

	//Свободный режим (никакой сборки, просто вращение граней вручную)
	void freeMode();

	//Сборка кубика стандартным способом
	void standartAssembly();
};

