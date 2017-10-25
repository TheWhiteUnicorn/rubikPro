#pragma once

#include "..\cube\Cube.h"
#include "..\assembly\Assembler.h"
#include "..\res\consoleManager.h"
#include "..\cv\InitialRecogniser.h"
#include "..\assembly\analysis\readinessAuditor.h"

//Класс, контролирующий основной процесс работы приложения
class Master
{
	//Рабочая модель кубика
	Cube _cube;
	Assembler _assembler{_cube};
	InitialRecogniser initRec;

	readinessAuditor readyAudit{ &_cube, &_assembler };

	void applyAllFormulas(FormulaStack& );
public:
	Master();
	~Master();

	void readEdges();

	//Свободный режим (никакой сборки, просто вращение граней вручную)
	void freeMode();

	//Сборка кубика стандартным способом
	void standartAssembly();

	void performOperation();
};