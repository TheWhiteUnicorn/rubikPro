#pragma once
#include "..\res\res.hpp"


class Cube
{
public:
	// Стандартный конструктор
	Cube();

	// Конструктор, принимающий массив граней
	Cube(color(&edg)[6][3][3]);

	// Деструктор
	~Cube();

	// Геттер для граней, возвращаемое значение недоступно для изменения
	const color *** get_edges();

	// Преобразовать кубик в собранное состояние
	void reset();


	void rotate();
private:
	void initEdges();
	color*** edges;
};

