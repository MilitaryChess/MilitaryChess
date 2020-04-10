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

int test_main()
{
	test_Chess();
	return 0;
}
