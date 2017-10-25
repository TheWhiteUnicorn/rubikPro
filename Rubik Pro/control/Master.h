#pragma once

#include "..\cube\Cube.h"
#include "..\assembly\Assembler.h"
#include "..\res\consoleManager.h"
#include "..\cv\InitialRecogniser.h"
#include "..\assembly\analysis\readinessAuditor.h"

//�����, �������������� �������� ������� ������ ����������
class Master
{
	//������� ������ ������
	Cube _cube;
	Assembler _assembler{_cube};
	InitialRecogniser initRec;

	readinessAuditor readyAudit{ &_cube, &_assembler };

	void applyAllFormulas(FormulaStack& );
public:
	Master();
	~Master();

	void readEdges();

	//��������� ����� (������� ������, ������ �������� ������ �������)
	void freeMode();

	//������ ������ ����������� ��������
	void standartAssembly();

	void performOperation();
};