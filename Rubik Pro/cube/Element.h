#pragma once
#include "../res/res.hpp"

//Слой, в котором находится элемент
enum ElementLocLayer {TOP, MID, BOT};

class ElementLocSide {
public:
	int side;
	// Пустой к-тор
	ElementLocSide() {}
	// Конструктор с параметром int
	ElementLocSide(int _side) : side(_side) {}

	ElementLocSide& operator=(int);
	ElementLocSide& operator++(); 
	ElementLocSide& operator--();
	ElementLocSide& operator+(int x);
	ElementLocSide& operator-(int x);
};

struct Element
{
	// Слой
	ElementLocLayer layer = TOP;
	// Направление
	ElementLocSide side = 0;
	// Флаг, указывающий на то, что элемент стоит на совем месте
	bool placed = false;

	// Пустой к-тор
	Element() {}
	// К-тор с параметрами
	Element(ElementLocLayer l, int s) : layer(l), side(s) {}

	// Установить позицию
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
	// Геттеры полей
	Color	get_primary() const { return primary; }
	Color	get_side1() const { return side1; }
	Color	get_side2() const { return side2; }
	int		get_orientation() const { return orientation; }

	// Пустой конструктор
	Corner() {}
	// Конструктор со всеми полями
	Corner(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation);
	// Установить все значения
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
	// Геттеры полей
	Color get_first() const { return first; };
	Color get_second() const { return second; };
	int get_orientation() const { return orientation; };

	//Пустой к-тор
	Edge() {}
	// Конструктор со всеми полями
	Edge(ElementLocLayer layer, int side, Color _first, Color _second, int orientation);
	// Установить все значения
	void set(ElementLocLayer layer, int side, Color _first, Color _second, int orientation); 
};