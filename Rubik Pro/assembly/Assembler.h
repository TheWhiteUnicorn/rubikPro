#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "Formula.h"


//�����, ���������� �� ������� ������. � ��� ������������ ������ ������ � ����������� ���������, ����������� �� ������� ����� ������
class Assembler {
	//������ �� ������ ������, � ������� ������ ������������ ������
	Cube & _cube;
	//����� ����������
	Analyser * _analyser;

	/// ��������� �������
	int findMidColor(Color color);
	Operation findOptimalYRot(int src, int tgt);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void allignCube(Formula &);
	void doTopCross(Formula &);
};

