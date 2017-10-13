#pragma once
#include "..\res\res.hpp"
#include "..\res\Formula.h"

class Cube
{
public:
	// Стандартный конструктор
	Cube();
	// Конструктор, принимающий массив граней
	Cube(Color(&edg)[6][3][3]);
	// К-тор копирования
	Cube(Cube&);
	// Деструктор
	~Cube();

	// Геттер для граней, возвращаемое значение недоступно для изменения
	const Color *** get_edges();

	// Преобразовать кубик в собранное состояние
	void reset();

	// Запутать кубик
	void trick(int numOfOperations);

	// Совершить поворот. принимает значение типа перечисления Move и Dir.
	void rotate(Move move, Dir dir);

	// Совершить поворот. принимает обект класса Operation.
	void rotate(Operation);

	// Coвершить поворот. принимает значения типа int 
	// move - код движения 
	// dir - направление поворота
	// move - от 0 до 17, dir - от 0 до 2
	void rotate(int move, int dir);

	// Применить готовую формулу к модели
	void applyFormula(Formula& f);

	Cube& operator=(Cube& cub);
private:
	// Массив граней
	Color*** edges;

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

