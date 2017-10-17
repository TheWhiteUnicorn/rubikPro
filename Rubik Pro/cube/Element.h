#pragma once
#include "../res/res.hpp"

//����, � ������� ��������� �������
enum ElementLocLayer {TOP, MID, BOT};

class ElementLocSide {
public:
	int side;
	// ������ �-���
	ElementLocSide() {}
	// ����������� � ���������� int
	ElementLocSide(int _side) : side(_side) {}

	ElementLocSide& operator=(int);
	ElementLocSide& operator++(); 
	ElementLocSide& operator--();
	ElementLocSide& operator+(int x);
	ElementLocSide& operator-(int x);
};

struct Element
{
	// ����
	ElementLocLayer layer = TOP;
	// �����������
	ElementLocSide side = 0;
	// ����, ����������� �� ��, ��� ������� ����� �� ����� �����
	bool placed = false;

	// ������ �-���
	Element() {}
	// �-��� � �����������
	Element(ElementLocLayer l, int s) : layer(l), side(s) {}

	// ���������� �������
	void set_pos(ElementLocLayer l, int s);
};

struct Corner : public Element
{
private:
	Color primary = WHITE; // ALWAYS White or Yellow
	Color side1 = WHITE;
	Color side2 = WHITE;

	// 0 - TOP/BOTTOM
	// 1 - CKW
	// 2 - ACKW
	int orientation = 0;

public:
	// ������� �����
	Color	get_primary() const { return primary; }
	Color	get_side1() const { return side1; }
	Color	get_side2() const { return side2; }
	int		get_orientation() const { return orientation; }

	// ������ �����������
	Corner() {}
	// ����������� �� ����� ������
	Corner(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation);
	// ���������� ��� ��������
	void set(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation); 
};

struct Edge : public Element
{
private:
	Color first; // white or yellow, if present
	Color second;

	// 0 - ACKW, first color oriented to TOP/BOTTOM
	// 1 - CKW, first color oriented to SIDE
	int orientation;

public:
	// ������� �����
	Color get_first() const { return first; };
	Color get_second() const { return second; };
	int get_orientation() const { return orientation; };

	//������ �-���
	Edge() {}
	// ����������� �� ����� ������
	Edge(ElementLocLayer layer, int side, Color _first, Color _second, int orientation);
	// ���������� ��� ��������
	void set(ElementLocLayer layer, int side, Color _first, Color _second, int orientation); 
};