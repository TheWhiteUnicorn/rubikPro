#pragma once
#include "../res/res.hpp"

//Слой, в котором находится элемент
enum ElementLocLayer {TOP, MID, BOT};

struct Element
{
	// Слой
	ElementLocLayer layer;
	// Направление
	int side;
};

struct Corner : public Element
{
	Color primary; // ALWAYS White or Yellow
	Color side1;
	Color side2;

	// 0 - TOP/BOTTOM
	// 1 - CKW
	// 2 - ACKW
	int orientation;
};

struct Edge : public Element
{
	Color first; // white or yellow, if present
	Color second;

	// 0 - CKW, first color oriented to TOP/BOTTOM
	// 1 - ACKW, first color oriented to SIDE
	int orientation;
};