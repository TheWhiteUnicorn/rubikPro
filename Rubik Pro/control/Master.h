#pragma once

#include "..\cube\Cube.h"
#include "..\res\consoleManager.h"

class Master
{
	Cube _cube;
public:
	Master();
	~Master();

	void freeMode();
	void standartAssembly();
};

