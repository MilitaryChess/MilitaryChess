#include <iostream>
#include <vector>
#include<queue>
#include "../../common.h"
using namespace std;

/**
* @file			
* @brief        返回铁路线上，工兵可以到达的所有位置
* @param[in]    工兵位置pair<int,int>,可以到达位置的vector，引用传入
* @param[out]   无(可以到达位置的返回由引用的vector带出
* @author       ssc
* @date			2020.04.14
* @version		0.0.2
*/
void LBChess::_get_gong(pair<int, int>pos, vector<pair<int, int>>& result)
{
	/*函数思路，使用BFS进行寻路，如果下一个位置是己方或者已经探索或者是公路线，则停止探索
	 如果是铁路线，则加入队列，等待搜索
	 从队列中出队列，进行上下左右搜索
	*/
	//cout <<"testget_gong   "<< pos.first << "  " << pos.second << endl;
	int group;//工兵是哪方阵营
	if (RAILWAY.count(position2int(pos.first, pos.second)) == 0 || abs(board[pos.first][pos.second]) != GONG) //非铁路线或者没有工兵则返回
		return;
	if (board[pos.first][pos.second] > 0)
		group = 1;
	else
		group = -1;//保证己方的字*group>0,对方的*group<0
	int temp[13][5] = {
		{0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0} };//内置铁路线地图，为了加快运行速度
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 5; j++)
		{
			if (temp[i][j] == 0)
				continue;
			if (board[i][j] * group > 0)
				temp[i][j] = -1;//自己人置1
			if (board[i][j] * group < 0)
				temp[i][j] = 2;//敌人置2
		}//重置地图，公路线位置是0，铁路线空白地方为0，自己位置为1，敌人位置为2

	result.clear();
	/*cout << "testget_gong   " << endl;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 5; j++)
			cout << temp[i][j]<<"  ";
		cout << endl;
	}*/
	queue<pair<int, int>> Q;
	Q.push(pos);
	pair<int, int> current, a;//临时变量，记录现在的位置
	while (Q.size() > 0)
	{
		current = Q.front();
		Q.pop();//出队列，然后记录
		//cout << "testget_gong   " << current.first << "  " << current.second << endl;
		result.push_back(current);//进入result中，代表可以走到
		temp[current.first][current.second] = -1;//代表已访问过
		if (current.first + 1 < 13) {
			if (temp[current.first + 1][current.second] == 1)
				Q.push(make_pair(current.first + 1, current.second));//如果是铁路，加入队列，等着下次访问
			else if (temp[current.first + 1][current.second] == 2)
				result.push_back(make_pair(current.first + 1, current.second));//如果是敌人，就可以走到这个位置，不能继续
			//如果是公路，己方，或者已经探索，则结束
		}
		if (current.second + 1 < 5) {
			if (temp[current.first][current.second + 1] == 1)
				Q.push(make_pair(current.first, current.second + 1));
			else if (temp[current.first][current.second + 1] == 2)
				result.push_back(make_pair(current.first, current.second + 1));
		}
		if (current.first - 1 >= 0) {
			if (temp[current.first - 1][current.second] == 1)
				Q.push(make_pair(current.first - 1, current.second));
			else if (temp[current.first - 1][current.second] == 2)
				result.push_back(make_pair(current.first - 1, current.second));
		}
		if (current.second - 1 >= 0) {
			if (temp[current.first][current.second - 1] == 1)
				Q.push(make_pair(current.first, current.second - 1));
			else if (temp[current.first][current.second - 1] == 2)
				result.push_back(make_pair(current.first, current.second - 1));
		}
	}
	result.erase(result.begin());//第一个元素是传入的pos,移除
	//cout << "testget_gong   " << result.size() << endl;
}
