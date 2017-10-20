#pragma once
#include "..\cube\Cube.h"
#include "..\cube\Element.h"
#include "analysis\Analyser.h"
#include "..\res\Formula.h"
#include <assert.h>
#include "formulasLib.h"


//�����, ���������� �� ������� ������. � ��� ������������ ������ ������ � ����������� ���������, ����������� �� ������� ����� ������
class Assembler {
	//������ �� ������ ������, � ������� ������ ������������ ������
	Cube & _cube;
	//������ �� ��������� ������ ����, ����������� �������, �� �� ������� ����� ����������� ������� �� ���� ������� ������
	Cube _liveCube;
	//����� ����������
	Analyser * _analyser;

	// +++++++++++++++ ��������� ������� +++++++++++++++++++
	// �����, �� ����� ����� ��������� ����
	int findMidColor(Color color, Cube & cube);
	// ����� ����� ����������� ������� ��� ������������ �������� � ����� ������� � ������
	Dir findOptimalYRot(int src, int tgt, ElementLocLayer layer);
	// ����� ����� ����������� ������� ��� ������������ �������� � ����� ������� � ������
	Dir findOptimalYRot(ElementLocSide& src, ElementLocSide& tgt, ElementLocLayer layer);
	// ����� ����� ����������� ������� ��� ������������ �������� � ����� ������� � ������
	Dir findOptimalYRot(ElementLocSide & src, int tgt, ElementLocLayer layer);
	// �����, �� ����� ������� �� ����������� ������� ������ � ����� ������ ������� �������
	ElementLocSide findCornAdvSide(Corner& corn);

	// ����������� ����� �����, �� ������� ��������� �������, � ������. �������
	ElementLocSide sideToAdv(int side);
	// ����������� ������. ������� � ����� �����, �� ������� ��������� �������
	int advToSide(ElementLocSide side);

	// ���������� �������� � ��������� � ����� �� ��������� � _liveCube
	Operation applyOperation(FormulaStack & res, Operation & oper);
	// ��������� � ���������� �������� � ��������� � ����� �� ��������� � _liveCube
	Operation applyOperation(FormulaStack & res, Move mov, Dir dir);
	// ���������� ��� �������� ������� � ��������� � ����� �� ��������� � _liveCube
	Operation applyOperation(FormulaStack & res, const vector<pair<Move, int>>);
	// ��������� ����� �� �������� � ��������� �����
	void allign(FormulaStack &, Color colorOnTop, Color colorOnFront);

public:
	Assembler(Cube & c);
	~Assembler();
	
	void refresh();
	void allignCube(FormulaStack &, Color colorOnTop, Color colorOnFront);
	void doTopCross(FormulaStack &);
	void doTopLayer(FormulaStack &);
	void doMidLayer(FormulaStack &);
	void doBotCross(FormulaStack &);
	void doBotFacet(FormulaStack &);
};

