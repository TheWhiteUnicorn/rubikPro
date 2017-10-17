#include "Formula.h"
#include "..\cube\Cube.h"

Operation& Operation::invert() {
	direction = direction == DOUBL ? direction : Dir(1 - int(direction));
	return *this;
}

Formula::Formula() {
}

void Formula::pushBack(Operation op) {
	sequence.push_back(op);
	if (!sequence.front().performed) {
		firstUnperf = sequence.begin();
	}
	//operationsCount++;
}

//Operation Formula::pop_front() {
//	//operationsCount--;
//	Operation answ = sequence.front();
//	sequence.pop_front();
//	return answ;
//}

const Operation & Formula::getFirstUnperfOper() const { // TODO исключительные ситуации
	return *firstUnperf;
}

void Formula::doFirstUnperfOper(Cube & cub) {
	cub.rotate(*firstUnperf);
	firstUnperf->performed = true;
	firstUnperf++;

	if (sequence.back().performed) performed = true;
}

void Formula::setAllUnperformed() {
	for (auto i = sequence.begin(); i != sequence.end(); i++) {
		i->performed = false;
	}
	firstUnperf = sequence.begin();
}

void Formula::clear() {
	sequence.clear();
	performed = false;
}

FormulaStack::FormulaStack() {
	newFormula();
}

const Operation & FormulaStack::getFirstUnperfOper() const {
	if (formulas.back().performed) throw 1;// исключение выбрасывается, если в списке нет невыполненных формул. Для избежания, следует проверять поле performed
	return firstUnperf->getFirstUnperfOper();
}

const Formula & FormulaStack::getFirstUnperfFormula() {
	if (formulas.back().performed) throw 1;// исключение выбрасывается, если в списке нет невыполненных формул. Для избежания, следует проверять поле performed
	while (firstUnperf->performed)
		firstUnperf++;
	return *firstUnperf;
}

int FormulaStack::doFirstUnperfOper(Cube & cub) {
	if (firstUnperf->get_sequence().size() == 0) return 0;
	firstUnperf->doFirstUnperfOper(cub);
	
	if (firstUnperf->get_sequence().back().performed == true) {
		firstUnperf->performed = true;
		firstUnperf++;
	}

	if (formulas.back().performed) return 0;
	return 1;
}

void FormulaStack::newFormula() {
	if(formulas.size() == 0 || formulas.back().get_sequence().size() != 0)
		formulas.push_back(Formula());

	if (!formulas.front().performed) {
		firstUnperf = formulas.begin();
	}
}

void FormulaStack::pushBack(Operation & oper) {
	formulas.back().pushBack(oper);
}

void FormulaStack::setAllUnperformed() {
	for (auto i = formulas.begin(); i != formulas.end(); i++) {
		i->performed = false;
	}
	firstUnperf = formulas.begin();
}

void FormulaStack::clear() {
	formulas.clear();
	newFormula();
}
