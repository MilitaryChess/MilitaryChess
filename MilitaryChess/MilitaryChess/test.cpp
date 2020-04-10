/**
* @file			test.cpp
* @brief        测试
* @details		测试已经写好的类
* @author       Bay
* @date			2020.04.10
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.10, 创建文档\n
*/
#include <utility>
#include <array>
#include "iostream"
#include "Chessboard.h"
using namespace std;

void test_Chess()
{
	char name = 'y';
	Chess chess(name);
	cout << "priority: " << chess.priority << endl;
	cout << "movability: " << chess.movablity << endl;
	cout << "type: " << chess.type << endl;
	cout << "side: " << chess.side << endl;
}

void test_Check()
{
	cout << "start testing class Check: " << endl;
	array<array<Check, 5>, 13> chessboard;
	for (int r = 0; r < 13; r++) {
		for (int c = 0; c < 5; c++) {
			chessboard[r][c].assign(make_pair('m' - r, c));
		}
	}

	for (int r = 0; r < 13; r++) {
		for (int c = 0; c < 5; c++)
			chessboard[r][c].output1();
		cout << endl;
		for (int c = 0; c < 5; c++)
			chessboard[r][c].output2();
		cout << endl; 
		for (int c = 0; c < 5; c++)
			chessboard[r][c].output3();
		cout << endl;
	}
}

int test_main()
{
	//test_Chess();
	test_Check();
	return 0;
}
