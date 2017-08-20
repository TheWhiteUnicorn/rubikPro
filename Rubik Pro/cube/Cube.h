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
	// ����� ����� ������� (��������������)
	void swH(int row, int edge1, int edge2);

	// ����� ����� ������� (������������)
	void swV(int col, int edge1, int edge2);
	
	void rot(int edge, bool CKW);

	
};

