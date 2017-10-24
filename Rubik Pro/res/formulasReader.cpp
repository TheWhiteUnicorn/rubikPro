#include "formulasReader.h"
#include <fstream>
#include <string>

#define FILENAME "standartAssembly.txt"
#define FILE_FULL_PATH "D:\\Programming\\Visual Studio\\Rubik Pro\\Rubik Pro\\formulasLib\\standartAssembly.txt"

const map<char, Move> charsToMoves {
	{ 'F', F },
	{ 'R', R },
	{ 'L', L },
	{ 'U', U },
	{ 'D', D },
	{ 'B', B },
	{ 'M', M },
	{ 'S', S },
	{ 'E', E },
	{ 'x', x },
	{ 'y', y },
	{ 'z', z }
};

void findMoveDir(string& operBuf, Move& mov, Dir& dir) {
	if (operBuf.size() >= 2 && operBuf[1] == 'w') {
		mov = Move(int(charsToMoves.at(operBuf[0]) + 9)); // те же буквы, но с w, они находятся в енуме на 9 позиций правее
		if (operBuf.size() == 2)
			dir = CKW;
		else if (operBuf[3] == '\'')
			dir = ACKW;
		else if (operBuf[3] == '2')
			dir = DOUBL;
	}
	else if (operBuf.size() <= 2) {
		mov = charsToMoves.at(operBuf[0]);
		if (operBuf.size() == 1)
			dir = CKW;
		else if (operBuf[2] == '\'')
			dir = ACKW;
		else if (operBuf[2] == '2')
			dir = DOUBL;
	}

}

void prepareFormulasForStandartAssembly(map<string, list<pair<Move, Dir>>>& res) { // сделать функцию универсальной под разные типы сборки
	/*ifstream flib(FILE_FULL_PATH);

	if (!flib.is_open()) throw 1; 

	string nameBuf;
	//list<pair<Move, Dir>> movesBuf;

	flib >> nameBuf;

	string operBuf;
	Dir dirBuf;
	Move moveBuf;
	while (true) {
		flib >> operBuf;
		findMoveDir(operBuf, moveBuf, dirBuf);
		res[nameBuf].push_back({ moveBuf, dirBuf });
	}*/
}
