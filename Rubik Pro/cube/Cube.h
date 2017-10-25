#pragma once
#include "..\res\res.hpp"
#include "..\res\Formula.h"

#define DISP_ALL_MOVEMENTS

// Хранит конфигурацию цветов на одной грани
struct FacetColorsMatrix {
	Color colors[3][3];
};

// Хранит все грани кубика с конфигурацей цветов на них
struct CubeColorsTable {
	FacetColorsMatrix facets[6];
};

class Cube
{
public:
	// Стандартный конструктор
	Cube();
	// Конструктор, принимающий массив граней
	Cube(Color(&edg)[6][3][3]);
	// Конструктор, принимающий 
	Cube(CubeColorsTable& cfg);
	// К-тор копирования
	Cube(Cube&);
	// Деструктор
	~Cube();

	// Геттер для граней, возвращаемое значение недоступно для изменения
	const Color *** get_edges() const;

	// Возвращает цвет наклейки по номеру грани и номеру наклейки в соответствии с разверткой
	const Color get_color(int facet, int num) const;

	void set(CubeColorsTable& cfg);

	// ВНИМАНИЕ! ИСПОЛЬЗОВАНИЕ ДАННОЙ ФУНКЦИИ МОЖЕТ ПРИВЕСТИ К НАРУШЕНИЮ ЦЕЛОСТНОСТИ МОДЕЛИ! 
	void set_color(Color col, int i, int j, int k);

	// Преобразовать кубик в собранное состояние
	void reset();

	// Запутать кубик
	void trick(int numOfOperations, int randomizerKey);

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
	
	// Оператор присваивания
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