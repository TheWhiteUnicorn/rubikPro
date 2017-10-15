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
	// �����, �� ����� ����� ��������� ����
	int findMidColor(Color color, Cube & cube);
	// ����� ����� ����������� ������� ��� ������������ �������� � ����� ������� � ������
	Dir findOptimalYRot(int src, int tgt, ElementLocLayer layer);
	Dir findOptimalYRot(ElementLocSide& src, ElementLocSide& tgt, ElementLocLayer layer);

	// ����������� ����� �����, �� ������� ��������� �������, � ������. �������
	ElementLocSide sideToAdv(int side);
	// ����������� ������. ������� � ����� �����, �� ������� ��������� �������
	int advToSide(ElementLocSide side);

	// ���������� �������� � ��������� � ����� �� ��������� � _liveCube
	Operation applyOperation(Formula & res, Operation & oper);
	// ��������� � ���������� �������� � ��������� � ����� �� ��������� � _liveCube
	Operation applyOperation(Formula & res, Move mov, Dir dir);
	// 
	void allign(Formula &, Color colorOnTop, Color colorOnFront);
public:
	Assembler(Cube & c);
	~Assembler();
	
	void refresh();
	void allignCube(Formula &, Color colorOnTop, Color colorOnFront);
	void doTopCross(Formula &);
};

