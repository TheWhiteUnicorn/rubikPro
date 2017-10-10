#pragma once
#include "../res/res.hpp"

//Слой, в котором находится элемент
enum ElementLocLayer {TOP, MID, BOT};

struct Element
{
	// Слой
	ElementLocLayer layer = TOP;
	// Направление
	int side = 0;
	// Флаг, указывающий на то, что элемент стоит на совем месте
	bool placed = false;

	// Пустой к-тор
	Element() {}
	// К-тор с параметрами
	Element(ElementLocLayer l, int s) : layer(l), side(s) {}

	// Установить позицию
	void set_pos(ElementLocLayer l, int s) {
		layer = l;
		side = s;
	}
	//virtual void set() {}
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
	Color	get_primary() const { return primary; };
	Color	get_side1() const { return side1; };
	Color	get_side2() const { return side2; };
	int		get_orientation() const { return orientation; };

	// Пустой конструктор
	//Corner() {}

	// Конструктор со всеми полями
	Corner(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation) :
		Element(layer, side), primary(primary), side1(side1), side2(side2), orientation(orientation) {

		// Подстройка для того, чтоб primary всегда был нужного цвета
		switch (orientation) {
		case 0: {
			primary = _primary;
			side1 = _side1;
			side2 = _side2;
			break;
		}
		case 1: {
			primary = _side1;
			side1 = _side2;
			side2 = _primary;
			break;
		}
		case 2: {
			primary = _side2;
			side1 = _primary;
			side2 = _side1;
			break;
		}
		}
	}

	//void set(Color prim, Color s1, Color s2) {

	//}
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

	// Конструктор со всеми полями
	Edge(ElementLocLayer layer, int side, Color _first, Color _second, int orientation) :
		Element(layer, side), first(_first), second(_second), orientation(orientation) {

		if (orientation == 0) { // Подстройка для того, чтоб first всегда был нужного цвета
			first = _first;
			second = _second;
		}
		else {
			first = _second;
			second = _first;
		}
	}
};