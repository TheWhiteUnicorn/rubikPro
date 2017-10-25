#pragma once
#include "..\res\res.hpp"
#include <deque>
class Cube;

using namespace std;



// ���������, �������� ������ ����� �������� ��� �������
struct Operation {
	// ��������
	Move move;
	// �����������
	Dir direction;

	bool performed = false;

	Operation() {};
	Operation(Move mov, Dir dir) : move(mov), direction(dir) {}

	// �������� �������� �� ������ �������� �������
	Operation& invert();
};

// ���������, �������� ����� �������� ��� ������� ����� ��������� ������ (��������, ��������� ������ �������� �� ������ �����)
struct Formula {
private:
	// ������������������ ��������
	deque<Operation> sequence;
	deque<Operation>::iterator firstUnperf;
	
public:
	// ��������, ����� ���������� ��������� ������ ��� �������
	string purpose;

	/*Color color1 = Color(-1); //���� ����� ������������������� ��������� -1, �� �������� �� ����
	Color color2 = Color(-1);
	Color color3 = Color(-1); */

	// ����������, ����������� �� ��� ��� ��������
	bool performed = false;

	Formula();
	const deque<Operation>& get_sequence() const { return sequence; }

	// �������� �������� � ����� �������
	void pushBack(Operation op); 


	// ������� ������ ��� �� ����������� ��������
	const Operation& getFirstUnperfOper() const;
	// ��������� ������ ��� �� ����������� ��������
	void doFirstUnperfOper(Cube& cub);

	// ��������� ��� ���� �������� ���� � ���, ��� ��� �� ���������
	void setAllUnperformed();

	// �������� �������
	void clear();
};

// ���������, �������� ������������ ������, ��������� ����������� ���� ���� ������ (��������, ������ �������� ������)
struct FormulaStack {
private:
	// ������������������ ������
	deque<Formula> formulas;
	deque<Formula>::iterator firstUnperf;
	
public:
	// ��������, ����� ���������� ������ ������ ��� ������������ ������
	string purpose;

	FormulaStack();
	// ���������� ������ �� ������� (�� ������������� ������������ ��� ����������/���������� ��������!!)
	deque<Formula>& get_formulas() { return formulas; }
	
	Formula& get_last();

	// ������� ������ ��� �� ����������� ��������
	const Operation& getFirstUnperfOper() const;

	// ������� ������ ��� �� ����������� �������
	const Formula& getFirstUnperfFormula();

	// ��������� ������ ��� �� ����������� ��������
	// ����������: 1 - ���� �������� ������� ���������, 0 - ���� ��� �������� ��� ���������
	int doFirstUnperfOper(Cube& cub);


	// �������� ����� ������ ������� � ����� �������
	void newFormula();
	// �������� �������� � �����
	void pushBack(Operation& oper);

	// ��������� ��� ���� ������ � �������� ���� � ���, ��� ��� �� ���������
	void setAllUnperformed();

	// �������� ����� ������
	void clear();
};