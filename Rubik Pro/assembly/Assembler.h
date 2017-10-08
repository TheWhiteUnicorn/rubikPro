#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"

//�����, ���������� �� ������� ������. � ��� ������������ ������ ������ � ����������� ���������, ����������� �� ������� ����� ������
class Assembler {
	//������ �� ������ ������, � ������� ������ ������������ ������
	Cube & _cube;
	//����� ����������
	Analyser * _analyser;

public:
	Assembler(Cube & c);
	~Assembler();
	
	void doTopCross();
};

