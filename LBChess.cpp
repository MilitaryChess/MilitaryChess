#include"common.h"
#include<array>
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

/*
LBChess类：
维护棋盘信息
确保行子和布阵的正确性
确保攻击的正确性
但不负责控制游戏流程
*/
class LBChess//棋盘类 
{
private:
	array<array<int, 5>, 13> board;
	vector<vector<int>> _tie = {
		{0, 0, 0, 0, 0} ,
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
		{0, 0, 0, 0, 0} };
public:
	LBChess() { board = {}; };//全零
	LBChess(const array<array<int, 5>, 13>& data) { board = data; };
	//move函数
	//get函数
	//__get__gong函数
	vector<pair<int, int>> get(pair<int, int>pos);
	bool tie(int x,int y);   //是否在铁路线上
	void _get_gong(pair<int, int> pos, vector<pair<int, int>>& result);
};
bool LBChess::tie(int x,int y) {
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
		SHANJIE.count(position2int(pos.first, pos.second)) )  //[大本营无法移动：暗棋规则]
		return result;
	//公路线，考虑周围八个位置
	for(int i=-1;i<2;i++)
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)
				continue;
			int new_row = pos.first + i;
			int new_col = pos.second + j;
			if (new_row < 0 || new_row>12 || new_col < 0 || new_col>4)    //不可移动到界外
				continue;
			if (SHANJIE.count(position2int(pos.first, pos.second)))   //不可移动到山界
				continue; 
			if (i != 0 && j != 0 && !XINGYING.count(position2int(pos.first, pos.second)) &&
				!XINGYING.count(position2int(new_row, new_col)))//斜方向上移动必须有一个在行营
				continue;
			if (XINGYING.count(position2int(new_row, new_col)) && board[new_row][new_col] != BLANK)//如果移动到行营，行营不可以有棋子
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
			if(tie(new_pos.first,new_pos.second)&&board[new_pos.first][new_pos.second]==BLANK)
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