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

	// ��������� �������, ��������� �������� ���� ������������ move
	void rotate(Move move);
private:
	// ������ ������
	color*** edges;

	// ������� ���������� ������ ������
	void initEdges();


	//## ������������ ������� ��� ���������
	// ������� ����, ������������� ��� X
	void sideRotX(int row, int dir);

	// ������� ����, ������������� ��� Y
	void sideRotY(int col, int dir);

	// ������� ����, ������������� ��� Z
	void sideRotZ(int col, int dir);
	
	void rot(int edge, bool CKW);

	
};

