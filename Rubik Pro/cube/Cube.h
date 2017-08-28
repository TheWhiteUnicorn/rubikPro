#pragma once
#include "..\res\res.hpp"

class Cube
{
public:
	// ����������� �����������
	Cube();

	// �����������, ����������� ������ ������
	Cube(color(&edg)[6][3][3]);

	// ����������
	~Cube();

	// ������ ��� ������, ������������ �������� ���������� ��� ���������
	const color *** get_edges();

	// ������������� ����� � ��������� ���������
	void reset();

	// ��������� �������. ��������� �������� ���� ������������ Move � Dir.
	// move - ��� �������� 
	// dir - ����������� ��������
	void rotate(Move move, Dir dir);

	// Co������� �������. ��������� �������� ���� int 
	// move - ��� �������� 
	// dir - ����������� ��������
	// move - �� 0 �� 17, dir - �� 0 �� 2
	void rotate(int move, int dir);

private:
	// ������ ������
	color*** edges;

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

