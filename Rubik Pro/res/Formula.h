#pragma once
#include "..\res\res.hpp"
#include <deque>

using namespace std;

struct Operation {
	// Движение
	Move move;
	// Направление
	Dir direction;
};

struct Formula {
private:
	deque<Operation> sequence;
	//int operationsCount;

public:
	const deque<Operation>& get_sequence() const { return sequence; }
	//const int get_operatonsCount() const { return operationsCount; }

	// Добавить операцию в конец очереди
	void push_back(Operation op) {
		sequence.push_back(op);
		//operationsCount++;
	}

	// Взять операцию из конца очереди с удалением ее
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