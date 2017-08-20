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
	// Обмен линий местами (горизонтальный)
	void swH(int row, int edge1, int edge2);

	// Обмен линий местами (вертикальный)
	void swV(int col, int edge1, int edge2);
	
	void rot(int edge, bool CKW);

	
};

