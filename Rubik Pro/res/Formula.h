#pragma once
#include "..\res\res.hpp"
#include <deque>
class Cube;

using namespace std;



// —труктура, хран€ща€ данные одной операции над кубиком
struct Operation {
	// ƒвижение
	Move move;
	// Ќаправление
	Dir direction;

	bool performed = false;

	Operation() {};
	Operation(Move mov, Dir dir) : move(mov), direction(dir) {}

	// «аменить операцию на другую обратную текущей
	Operation& invert();
};

// —труктура, хран€ща€ набор операций дл€ решени€ одной отдельной задачи (например, установка одного элемента на нужное место)
struct Formula {
private:
	// ѕоследовательность операций
	deque<Operation> sequence;
	deque<Operation>::iterator firstUnperf;
	
public:
	// ќтражает, какую конкретную подзадачу решает эта формула
	string purpose;

	/*Color color1 = Color(-1); //≈сли цвета проинициализированы значением -1, их выводить не надо
	Color color2 = Color(-1);
	Color color3 = Color(-1); */

	// ѕоказывает, примен€лась ли уже эта операци€
	bool performed = false;

	Formula();
	const deque<Operation>& get_sequence() const { return sequence; }

	// ƒобавить операцию в конец очереди
	void pushBack(Operation op); 


	// ¬ернуть первую еще не примененную операцию
	const Operation& getFirstUnperfOper() const;
	// ѕрименить первую еще не примененную операцию
	void doFirstUnperfOper(Cube& cub);

	// ¬ыставить дл€ всех операций флаг о том, что они не выполнены
	void setAllUnperformed();

	// ќчистить формулу
	void clear();
};

// —труктура, хран€ща€ совокупность формул, полностью выполн€ющих один этап сборки (например, сборка верхнего креста)
struct FormulaStack {
private:
	// ѕоследовательность формул
	deque<Formula> formulas;
	deque<Formula>::iterator firstUnperf;
	
public:
	// ќтражает, какую конкретную задачу решает эта совокупность формул
	string purpose;

	FormulaStack();
	// ¬озвращает ссылку на формулы (не рекомендуетс€ использовать дл€ добавлени€/выполнени€ операций!!)
	deque<Formula>& get_formulas() { return formulas; }
	
	Formula& get_last();

	// ¬ернуть первую еще не примененную операцию
	const Operation& getFirstUnperfOper() const;

	// ¬ернуть первую еще не примененную формулу
	const Formula& getFirstUnperfFormula();

	// ѕрименить первую еще не примененную операцию
	// ¬озвращает: 1 - если операци€ успешно применена, 0 - если все операции уже применены
	int doFirstUnperfOper(Cube& cub);


	// ƒобавить новую пустую формулу в конец очереди
	void newFormula();
	// ƒобавить операцию в конец
	void pushBack(Operation& oper);

	// ¬ыставить дл€ всех формул и операций флаг о том, что они не выполнены
	void setAllUnperformed();

	// ќчистить набор формул
	void clear();
};