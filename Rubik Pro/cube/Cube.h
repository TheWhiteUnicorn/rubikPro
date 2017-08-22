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

	// Совершить поворот, принимает значение типа перечисления move
	void rotate(Move move);
private:
	// Массив граней
	color*** edges;

	// Создать трехмерный массив граней
	void initEdges();


	//## Элементарные функции для поворотов
	// Поворот слоя, параллельного оси X
	void sideRotX(int row, int dir);

	// Поворот слоя, параллельного оси Y
	void sideRotY(int col, int dir);

	// Поворот слоя, параллельного оси Z
	void sideRotZ(int col, int dir);
	
	void rot(int edge, bool CKW);

	
};

