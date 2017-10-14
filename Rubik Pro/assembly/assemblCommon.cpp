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

Dir Assembler::findOptimalYRot(int src, int tgt) {
	Dir answ;
	int diff = src - tgt;

	diff = diff == -2 ? 2 : diff; // �������� -2 �� 2

	switch (diff)
	{
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
	return answ;
}

//�������������� �������������� �� ���� ������� ����� (1-4) � ��� �� ����������� ������� ���������������� (������ ��� ��������� �����!)
int Assembler::sideCoordOfEdgeToAdvancedPos(int side) {
	assert(side >= 1 && side <= 4);

	switch (side) {
	case 1: return 3;
	case 2: return 0;
	case 3: return 1;
	case 4: return 2;
	}
}

// ���������� �������� � ��������� � ����� �� ��������� � _liveCube
void Assembler::applyOperation(Formula & res, Operation & oper) {
	res.push_back(oper);
	_liveCube.rotate(oper);
}