#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "..\res\Formula.h"


//�����, ���������� �� ������� ������. � ��� ������������ ������ ������ � ����������� ���������, ����������� �� ������� ����� ������
class Assembler {
	//������ �� ������ ������, � ������� ������ ������������ ������
	Cube & _cube;
	//������ �� ��������� ������ ����, ����������� �������, �� �� ������� ����� ����������� ������� �� ���� ������� ������
	Cube _liveCube;
	//����� ����������
	Analyser * _analyser;

	// ��������� �������
	int findMidColor(Color color, Cube & cube);
	Dir findOptimalYRot(int src, int tgt);
	int sideCoordOfEdgeToAdvancedPos(int side);
	// ���������� �������� � ��������� � ����� �� ��������� � _liveCube
	void applyOperation(Formula & res, Operation & oper);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void allignCube(Formula &, Color colorOnTop, Color colorOnFront);
	void doTopCross(Formula &);
};

