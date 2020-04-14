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
*/
//ppdfd / plldz / z3y / yt1ty / s1g1s / jvgva / 5 / JVGVA / S1G1S / YT1TY / Z1G1Y / PLLDZ / PPDFD
//对应
/*
 -5  -5  -2  -1  -2
 -5  -6  -6  -2  -3
 -3   0   0   0  -7
 -7  -8   0  -8  -7
-10   0  -4   0 -10
-11  -9  -4  -9 -12
  0   0   0   0   0
 11   9   4   9  12
 10   0   4   0  10
  7   8   0   8   7
  3   0   4   0   7
  5   6   6   2   3
  5   5   2   1   2
*/
