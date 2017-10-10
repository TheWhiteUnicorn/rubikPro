#pragma once
#include "..\..\cube\Cube.h"

class readinessAuditor
{
	Cube * _cube;
public:
	readinessAuditor(Cube*);
	~readinessAuditor();
};

