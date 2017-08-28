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

	// Совершить поворот. принимает значение типа перечисления Move и Dir.
	// move - код движения 
	// dir - направление поворота
	void rotate(Move move, Dir dir);

	// Coвершить поворот. принимает значения типа int 
	// move - код движения 
	// dir - направление поворота
	// move - от 0 до 17, dir - от 0 до 2
	void rotate(int move, int dir);

private:
	// Массив граней
	color*** edges;

	// Создать трехмерный массив граней
	void initEdges();


	//## Элементарные функции для поворотов
	// Поворот слоя, параллельного оси X
	void sideRotX(int row, Dir dir);

	// Поворот слоя, параллельного оси Y
	void sideRotY(int col, Dir dir);

	// Поворот слоя, параллельного оси Z
	void sideRotZ(int col, Dir dir);
	
	// Поворот боковой плоскости слоя
	void rot(int edge, Dir dir);
};

