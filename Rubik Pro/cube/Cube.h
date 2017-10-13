#pragma once
#include "..\res\res.hpp"
#include "..\res\Formula.h"

class Cube
{
public:
	// ����������� �����������
	Cube();
	// �����������, ����������� ������ ������
	Cube(Color(&edg)[6][3][3]);
	// �-��� �����������
	Cube(Cube&);
	// ����������
	~Cube();

	// ������ ��� ������, ������������ �������� ���������� ��� ���������
	const Color *** get_edges();

	// ������������� ����� � ��������� ���������
	void reset();

	// �������� �����
	void trick(int numOfOperations);

	// ��������� �������. ��������� �������� ���� ������������ Move � Dir.
	void rotate(Move move, Dir dir);

	// ��������� �������. ��������� ����� ������ Operation.
	void rotate(Operation);

	// Co������� �������. ��������� �������� ���� int 
	// move - ��� �������� 
	// dir - ����������� ��������
	// move - �� 0 �� 17, dir - �� 0 �� 2
	void rotate(int move, int dir);

	// ��������� ������� ������� � ������
	void applyFormula(Formula& f);

	Cube& operator=(Cube& cub);
private:
	// ������ ������
	Color*** edges;

	// ������� ���������� ������ ������
	void initEdges();


	//## ������������ ������� ��� ���������
	// ������� ����, ������������� ��� X
	void sideRotX(int row, Dir dir);

	// ������� ����, ������������� ��� Y
	void sideRotY(int col, Dir dir);

	// ������� ����, ������������� ��� Z
	void sideRotZ(int col, Dir dir);
	
	// ������� ������� ��������� ����
	void rot(int edge, Dir dir);
};

