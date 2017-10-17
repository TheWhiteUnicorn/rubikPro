#include "Assembler.h"
#include <cassert>

// +++++++++++ ��������� ������� +++++++++++++
int Assembler::findMidColor(Color color, Cube & cube) {
	int res = -1;
	for (int i = 0; i < 6; i++) {
		if (cube.get_edges()[i][1][1] == color) {
			res = i;
			break;
		}
	}
	return res;
}

Dir Assembler::findOptimalYRot(int src, int tgt, ElementLocLayer layer) {
	Dir answ;


	int diff = src - tgt;

	diff = diff == -2 ? 2 : diff; // �������� -2 �� 2

	switch (diff) {
	case -1: {
		answ = CKW;
		break;
	}
	case 0: {
		answ = NONE;
		break;
	}
	case 1: {
		answ = ACKW;
		break;
	}
	case 2: {
		answ = DOUBL;
		break;
	}
	case 3: {
		answ = CKW;
		break;
	}
	case -3: {
		answ = ACKW;
		break;
	}
	default:
		break;
	}

	if (layer == BOT) { // ���� ������� �� ������ ����, �������� ���� �������������
		answ = answ == 2 ? answ : Dir(1 - int(answ));
	}
	return answ;
}

Dir Assembler::findOptimalYRot(ElementLocSide& src, ElementLocSide& tgt, ElementLocLayer layer) {
	return findOptimalYRot(src.side, tgt.side, layer);
}

Dir Assembler::findOptimalYRot(ElementLocSide& src, int tgt, ElementLocLayer layer) {
	return findOptimalYRot(src.side, tgt, layer);
}

ElementLocSide Assembler::findCornAdvSide(Corner & corn) {
	return sideToAdv(findMidColor(corn.get_side1(), _liveCube));
}

//�������������� �������������� �� ���� ������� ����� (1-4) � ��� �� ����������� ������� ���������������� (������ ��� ��������� �����!)
ElementLocSide Assembler::sideToAdv(int side) {
	assert(side >= 0 && side <= 5 && side != 2 && side != 4);

	switch (side) {
	case 1: return ElementLocSide(3);
	case 5: return ElementLocSide(0);
	case 3: return ElementLocSide(1);
	case 0: return ElementLocSide(2);
	}
}

//�������������� �������������� �� ���� �� ����������� ������� ���������������� � ����� ������� ����� (������ ��� ��������� �����!)
int Assembler::advToSide(ElementLocSide side) {
	switch (side.side) {
	case 0: return 5;
	case 1: return 3;
	case 2: return 0;
	case 3: return 1;
	}
}

// ���������� �������� � ��������� � ����� �� ��������� � _liveCube
Operation Assembler::applyOperation(FormulaStack & res, Operation & oper) {
	res.pushBack(oper);
	_liveCube.rotate(oper);
	return oper;
}

Operation Assembler::applyOperation(FormulaStack & res, Move mov, Dir dir) {
	Operation oper{ mov, dir };
	res.pushBack(oper);
	_liveCube.rotate(oper);
	return oper;
}

void Assembler::allign(FormulaStack & res, Color colorOnTop, Color colorOnFront) {
	assert(colorOnTop != colorOnFront); // ����� �������� � ������� ������������ �������� �� ����� ���������

	int topPos = findMidColor(colorOnTop, _liveCube);

	switch (topPos)
	{
	case 0: {
		applyOperation(res, Operation{ x, CKW });
		break;
	}
	case 1: {
		applyOperation(res, Operation{ z, CKW });
		break;
	}
	case 3: {
		applyOperation(res, Operation{ z, ACKW });
		break;
	}
	case 4: {
		applyOperation(res, Operation{ x, DOUBL });
		break;
	}
	case 5: {
		applyOperation(res, Operation{ x, ACKW });
		break;
	}
	default:
		break;
	}

	int frontPos = findMidColor(colorOnFront, _liveCube);
	applyOperation(res, Operation{ y, findOptimalYRot(sideToAdv(frontPos).side, 2, TOP) });
}