#pragma once
#include "..\res\res.hpp"
#include <deque>

using namespace std;

struct Operation {
	// ��������
	Move move;
	// �����������
	Dir direction;
};

struct Formula {
private:
	deque<Operation> sequence;
	//int operationsCount;

public:
	const deque<Operation>& get_sequence() const { return sequence; }
	//const int get_operatonsCount() const { return operationsCount; }

	// �������� �������� � ����� �������
	void push_back(Operation op) {
		sequence.push_back(op);
		//operationsCount++;
	}

	// ����� �������� �� ����� ������� � ��������� ��
	Operation pop_front() {
		//operationsCount--;
		Operation answ = sequence.front();
		sequence.pop_front();
		return answ;
	}	

	void clear() {
		sequence.clear();
	}
};