#include<iostream>
#include "common.h"
#include"tools.h"
using namespace std;

/**
* @file			test.cpp
* @brief        测试ncn和棋盘转化
* @param[in]    Ncn串
* @param[out]   打印棋盘状态，没有子的位置为0，有子的位置显示内部数组的值，行营用*标出
* @author       ssc
* @date			2020.04.18
* @version		0.0.1
*/
void test_ncn(const char s[])
{
	LBChess t;
	int a = 0, b = 0;
	t.parse_ncn(s, a, b);
	t.seetheboard();
}

/**
* @file			test.cpp
* @brief        测试棋子可以达到的位置
* @param[in]    Ncn串
* @param[out]   打印棋盘状态，棋子现在所在的位置用*标出，可以走的位置置1，不能到的位置置0
* @author       ssc
* @date			2020.04.20
* @version		0.0.1
*/
void test_move(const int row, const int col, const char s[])
{
	LBChess t;
	vector<pair<int,int>>res;
	int a = 0, b = 0;
	t.parse_ncn(s, a, b);//输入ncn，转化成棋盘
	t.seetheboard();//显示棋局样式
	cout << endl << endl;
	res = t.get(make_pair(row, col));//得到可以到的位置，存入res
	char r[13][5] ;
	int i, j;
	for (i = 0; i < 13; i++)
		for (j = 0; j < 5; j++)
			r[i][j] = '0';
	r[row][col] = '*';//设置一个二维数组，初始全是0，然后当前位置置*
	for (auto p = res.begin(); p != res.end(); p++)
		r[(*p).first][(*p).second] = '1';//返回的vector中对应的位置，在二维数组中置1
	//打印二维数组
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 5; j++)
			cout << r[i][j] << "  ";
		cout << endl;
	}
}
int main()
{
	test_move(2,1,"5/1Pg2/1gg11/212/s1g11/jvg11/5/JVGVA/S1G1S/YT1TY/Z1G1Y/PLLDZ/PPDFD");
}