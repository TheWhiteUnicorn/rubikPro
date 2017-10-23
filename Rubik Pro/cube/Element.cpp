#include "Element.h"

//+++++++++++++++++++++++ ElementLocSize +++++++++++++++++++++++++
ElementLocSide & ElementLocSide::operator++() {
	side++;
	if (side == 4) side = 0;
	return *this;
}

ElementLocSide & ElementLocSide::operator--() {
	side--;
	if (side == -1) side = 3;
	return *this;
}

ElementLocSide & ElementLocSide::operator+(int x) {
	ElementLocSide res(this->side);
	for (int i = 0; i < x; i++) {
		++res;
	}
	return res;
}

ElementLocSide & ElementLocSide::operator-(int x) {
	ElementLocSide res(this->side);
	for (int i = 0; i < x; i++) {
		--res;
	}
	return res;
}

ElementLocSide & ElementLocSide::operator=(int _side) {
	side = _side;
	return *this;
}


//+++++++++++++++++++++++ Element ++++++++++++++++++++++++++++++++
void Element::set_pos(ElementLocLayer l, int s) {
	layer = l;
	side = s;
}


//+++++++++++++++++++++++ Corner +++++++++++++++++++++++++++++++++
Corner::Corner(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation) :
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

void Corner::set(ElementLocLayer layer, int side, Color _primary, Color _side1, Color _side2, int orientation) {
	this->layer = layer;
	this->side = side;
	primary = _primary;
	side1 = _side1;
	side2 = _side2;
	this->orientation = orientation;

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



// +++++++++++++++++++++++ Edge ++++++++++++++++++++++++++++++++++
Edge::Edge(ElementLocLayer layer, int side, Color _first, Color _second, int orientation) :
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

void Edge::set(ElementLocLayer layer, int side, Color _first, Color _second, int orientation) {
	this->layer = layer;
	this->side = side;
	first = _first;
	second = _second;
	this->orientation = orientation;

	if (orientation == 0) { // Подстройка для того, чтоб first всегда был нужного цвета
		first = _first;
		second = _second;
	}
	else {
		first = _second;
		second = _first;
	}
}