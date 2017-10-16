#pragma once

#include "..\cube\Cube.h"
#include "..\assembly\Assembler.h"
#include "..\res\consoleManager.h"

//�����, �������������� �������� ������� ������ ����������
class Master
{
	//������� ������ ������
	Cube _cube;
	Assembler _assembler{_cube};

	void applyAllFormulas(FormulaStack& );
public:
	Master();
	~Master();

	//��������� ����� (������� ������, ������ �������� ������ �������)
	void freeMode();

	//������ ������ ����������� ��������
	void standartAssembly();
};

