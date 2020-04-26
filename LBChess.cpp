#include"common.h"
#include<array>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
/**
* @file			LBChess.cpp
* @brief        判断是否结束
* @param[in]    棋盘数组
* @param[out]   如果和局返回0，否则返回赢家R代表-1，B代表1，如果没有结束返回2
* @author       zzh
* @date			2020.04.13
* @version		0.0.1
*/
int end(const array<array<int, 5>, 13>& board)
{
	//判断军旗是否被吃
	bool FlagR = false, FlagB = false;
	//判断是否存在可以移动的力量
	bool live_R = false, live_B = false;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == FLAG)//B是正数，R是负数
				FlagB = true;
			else if (board[i][j] == -FLAG)
				FlagR = true;
			else if (board[i][j] >= 3 && board[i][j] <= 12)
				live_B = true;
			else if (board[i][j] <= -3 && board[i][j] >= -12)
				live_R = true;
		}
	if (!FlagB)  return R;
	if (!FlagR)  return B;
	if (!live_B && !live_R)//和局
		return 0;
	if (live_B && live_R)//未结束
		return 2;
	return live_B ? B : R;
}


/**
* @file			LBChess.cpp
* @brief        根据棋子等级判断攻击情况
* @param[in]    src : 攻击者 dst : 攻击目标
* @param[out]   同归于尽返回0，攻击成功返回1，攻击失败返回 - 1
* @author       zzh
* @date			2020.04.13
* @version		0.0.1
*/
int attack(int src, int dst)
{
	if (abs(src) == DI || abs(src) == FLAG || src * dst >= 0) // 攻击者不能是地雷或军旗或空白，双方不能是同一颜色，否则报错
		cout << "非法的攻击者" << endl;
	src = abs(src); dst = abs(dst);
	if (dst == ZHA or src == ZHA)  // 炸弹必然同归于尽
		return 0;
	if (dst == DI)  // 工兵排地雷，否则同归于尽
		return src == GONG ? 1 : 0;
	if (src == dst)  // 相同则同归于尽
		return 0;
	if (dst == FLAG)  // 军旗最弱
		return 1;
	return src > dst ? 1 : -1;
}



bool LBChess::tie(int x, int y) {
	return(x >= 0 && y >= 0 && x <= 12 && y <= 4 && _tie[x][y] == 1);
}

/**
* @file       LBChess.cpp
* @brief      得到某一位置棋子可以走的所有位置
* @author     zjx
* @date        2020.4.14
* @param[in]   pos    位置坐标
* @param[out]  result   所有可到达位置
* @par history
		zjx于2020.4.14创建\n
*/
vector<pair<int, int>>LBChess::get(pair<int, int>pos) {
	vector<pair<int, int>>result;
	if (abs(board[pos.first][pos.second]) == BLANK || abs(board[pos.first][pos.second]) == FLAG || abs(board[pos.first][pos.second]) == DI ||
		SHANJIE.count(position2int(pos.first, pos.second)))  //[大本营无法移动：暗棋规则]
		return result;
	//公路线，考虑周围八个位置
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)
				continue;
			int new_row = pos.first + i;
			int new_col = pos.second + j;
			if (new_row < 0 || new_row>12 || new_col < 0 || new_col>4)    //不可移动到界外
				continue;
			if (SHANJIE.count(position2int(new_row, new_col)))   //不可移动到山界
				continue;
			if (i != 0 && j != 0 && !XINGYING.count(position2int(pos.first, pos.second)) &&
				!XINGYING.count(position2int(new_row, new_col)))//斜方向上移动必须有一个在行营
				continue;
			if (XINGYING.count(position2int(new_row, new_col)) && board[new_row][new_col] != BLANK)//如果移动到行营，行营不可以有棋子
				continue;
			if (board[new_row][new_col] != 0 && board[pos.first][pos.second] != 0 && board[new_row][new_col] * board[pos.first][pos.second] > 0)
				continue;
			result.push_back(make_pair(new_row, new_col));
		}

	//铁路线，考虑直线路径，如果是工兵，使用工兵的寻路算法
	if (!tie(pos.first, pos.second))
		return result;
	if (abs(board[pos.first][pos.second]) == GONG)
		_get_gong(pos, result);
	else
	{
		int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		for (int i = 0; i < 4; i++) {
			pair<int, int> new_pos = make_pair(pos.first + direct[i][0], pos.second + direct[i][1]);
			if (tie(new_pos.first, new_pos.second) && board[new_pos.first][new_pos.second] == BLANK)
				while (true) {
					new_pos.first = new_pos.first + direct[i][0];
					new_pos.second = new_pos.second + direct[i][1];
					if (!tie(new_pos.first, new_pos.second))  //非铁路坐标
						break;
					if (board[new_pos.first][new_pos.second] * board[pos.first][pos.second] > 0)  //同色遮挡
						break;
					result.push_back(new_pos);
					if (board[new_pos.first][new_pos.second] * board[pos.first][pos.second] < 0)
						break;
				}
		}
	}
	return result;

}

/**
* @file			LBChess.cpp
* @brief        返回铁路线上，工兵可以到达的所有位置
* @param[in]    工兵位置pair<int, int>, 可以到达位置的vector，引用传入
* @param[out]   无(可以到达位置的返回由引用的vector带出
* @author       ssc
* @date			2020.04.14
* @version		0.0.2
*/
void LBChess::_get_gong(pair<int, int>pos, vector<pair<int, int>>& res)
{
	/*函数思路，使用BFS进行寻路，如果下一个位置是己方或者已经探索或者是公路线，则停止探索
	 如果是铁路线，则加入队列，等待搜索
	 从队列中出队列，进行上下左右搜索
	*/
	//cout <<"testget_gong   "<< pos.first << "  " << pos.second << endl;
	int group;//工兵是哪方阵营
	//if (RAILWAY.count(position2int(pos.first, pos.second)) == 0 || abs(board[pos.first][pos.second]) != GONG) //非铁路线或者没有工兵则返回
		//return;
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
				temp[i][j] = -1;//自己人置-1
			if (board[i][j] * group < 0)
				temp[i][j] = 2;//敌人置2
		}//重置地图，公路线位置是0，铁路线空白地方为0，自己位置为1，敌人位置为2

	vector<pair<int, int>>result;
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
	vector<pair<int, int>> res_tmp = res;
	res.clear();//res结果赋给新的vector，并清空
	for (auto p = res_tmp.begin(); p != res_tmp.end(); p++)
		if (_tie[(*p).first][(*p).second] == 0)
			res.push_back(make_pair((*p).first, (*p).second));//找到所有非铁路线位置，进入vector，为了去掉重复
	res.insert(res.end(), result.begin(), result.end());//把在铁路线可到达位置进入，
	//cout << "testget_gong   " << result.size() << endl;
}

/**
* @file			LBChess.cpp
* @brief        查看棋盘当前状态
* @param[in]    /
* @param[out]   打印棋盘状态，没有子的位置为0，有子的位置显示内部数组的值，行营用*标出
* @author       ssc
* @date			2020.04.18
* @version		0.0.1
*/
void LBChess::seetheboard()
{
	int i, j;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 5; j++)
		{
			if (XINGYING.count(position2int(i, j)) > 0)
				cout << setw(4) << "*" << board[i][j] << "*";
			else
				cout << setw(5) << board[i][j];
		}
		cout << endl;
	}
}


/**
* @file			LBChess.cpp
* @brief        查看输入一方，返回所有可以移动的位置
* @param[in]    B = 1，对方黑方大写字母    R = -1 本方红方小写字母
* @param[out]   pair<pair<int, int>, pair<int, int>>，返回所有可以移动的点对
* @author       ssc
* @date			2020.04.26
* @version		0.0.1
*/
vector<pair<pair<int, int>, pair<int, int>>>LBChess::get_all_canreach(const int state)
{
	vector<pair<pair<int, int>, pair<int, int>>> v;
	for (int i=0;i<13;i++)
		for (int j = 0; j < 5; j++)//循环整个棋盘
		{	
			if (state*board[i][j] > 0)//相乘大于0，代表有子，且是我方
			{
				pair<int, int> pos_now = make_pair(i, j);//当前位置的pair，提前生成，减少以后每次生成的开销
				vector<pair<int, int>> tmp = get(pos_now);//返回pos_now可以到达的所有位置
				for (auto p = tmp.begin(); p != tmp.end(); p++)
					v.push_back(make_pair(pos_now, *p));//由pos_now和迭代器p所指的值构成的pair，进入vector
			}
		}
	return v;
}
