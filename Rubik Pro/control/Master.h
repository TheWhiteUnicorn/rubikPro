#pragma once

#include "..\cube\Cube.h"
#include "..\assembly\Assembler.h"
#include "..\res\consoleManager.h"
//#include "..\cv\RubikState.h"

//�����, �������������� �������� ������� ������ ����������
class Master
{
	//������� ������ ������
	Cube _cube;
	Assembler _assembler{_cube};
	//RubikState state;


public:
	Master();
	~Master();

	void readEdges();

	//��������� ����� (������� ������, ������ �������� ������ �������)
	void freeMode();

	//������ ������ ����������� ��������
	void standartAssembly();

	//RubikState getState();
};