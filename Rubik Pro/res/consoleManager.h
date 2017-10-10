#pragma once

#include <iostream>
#include <Windows.h>
#include "res.hpp"
#include "..\cube\Cube.h"



// Отобразить развертку граней кубика
void dispEdges(const Color *** edg);

void cubeDemo(Cube& cube);