#pragma once
#include "..\..\cube\Cube.h"
#include "..\Assembler.h"

class readinessAuditor
{
	Cube * _cube;
	Assembler * assembler;
public:
	readinessAuditor(Cube*, Assembler*);
	~readinessAuditor();

	bool topCross();
	bool topLayer();
	bool midLayer();
	bool botCross();
	bool botFacet();
	bool botCorns();

	bool cubeReady();
};

