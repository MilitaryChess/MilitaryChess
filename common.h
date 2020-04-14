#pragma once
#include"tools.h"
#include<string>
#include<unordered_set>
using namespace std;
/*关于数据机构定义的简要说明
参照了助教的代码
array<array<int, 5>, 13>代表整个棋盘
数字代表棋子，也标记了棋子的优先级，红黑双方用数字的正负号表示

关于大本营、行营、山界，公路还是铁路，设置了一系列全局常变量unorder_set存储，***只需要存储一次，减少了内存消耗***
使用时只需要查询 if (XINGYING.count(position(x,y) != 0) 就表明（x，y)坐标是行营
                 if (RAILWAY.count(position(x,y) != 0) 就表明（x，y)坐标是铁路
				 position(x,y)是自己写的函数，使用时需要包含头文件"tools.h",用来把（x,y)转化为int,因为unordered_set不接受pair<int,int>类型
由于unorder_set的内部设计类似于哈希表，所以查询的时间复杂度约为O（1）

关于上下左右哪个方向有路，
1.只有大本营可以8个方向有路
2.最中间那一行只有上下2个方向
3.其余都是在棋盘范围内最多有4个方向
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
struct Chess {//棋子类
	string name;//名字
	int num;//优先级
	int n;//总数量
};
const int BLANK = 0;  // 空白
const int FLAG = 1;  // 军旗
const int DI = 2; //地雷
const int ZHA = 3;  // 炸弹
const int GONG = 4;  // 工兵
const int PAI = 5;  // 排长
const int LIAN = 6;  // 连长
const int YING = 7;  // 营长
const int TUAN = 8;  // 团长
const int LV = 9;  // 旅长
const int SHI = 10;  // 师长
const int JUN = 11;  // 军长
const int SI = 12;  // 司令

const Chess CHESS[13] = {
	Chess{"BLANK", 0, -1},
		Chess{"FLAG", 1, 1},
		Chess{"DI", 2, 3},
		Chess{"ZHA", 3, 2},
		Chess{"GONG", 4, 3},
		Chess{"PAI", 5, 3},
		Chess{"LIAN", 6, 3},
		Chess{"YING", 7, 2},
		Chess{"TUAN", 8, 2},
		Chess{"LV", 9, 2},
		Chess{"SHI", 10, 2},
		Chess{"JUN", 11, 1},
		Chess{"SI", 12, 1}
};

//[0,13]
//例：黑方排长的编码值 = B * pai， 红方军长的编码值 = R * jun
const int B = 1; //对方黑方大写字母
const int R = -1; //本方红方小写字母

//以左下角为原点
//行营坐标
const unordered_set<int> XINGYING = { position2int(2, 1), position2int(2, 3), position2int(3, 2), position2int(4, 1), position2int(4, 3), position2int(8, 1),
position2int(8, 3), position2int(9, 2), position2int(10, 1), position2int(10, 3) };  

//山界坐标
const unordered_set<int> SHANJIE = { position2int(6, 1), position2int(6, 3) };  

//大本营坐标
const unordered_set<int> DABENYING = { position2int(0, 1), position2int(0, 3), position2int(12, 1), position2int(12, 3) };  

//铁路线坐标
const unordered_set<int> RAILWAY = { position2int(1, 0), position2int(1, 1), position2int(1, 2), position2int(1, 3), position2int(1, 4),
position2int(2, 0),position2int(2, 4),position2int(3, 0),position2int(3, 4),position2int(4, 0),position2int(4, 4),
position2int(5, 0), position2int(5, 1), position2int(5, 2), position2int(5, 3), position2int(5, 4),
position2int(6, 0),position2int(6, 2),position2int(6, 4),
position2int(7, 0), position2int(7, 1), position2int(7, 2), position2int(7, 3), position2int(7, 4),
position2int(8, 0), position2int(8, 4), position2int(9, 0), position2int(9, 4), position2int(10, 0),position2int(10, 4),
position2int(11, 0), position2int(11, 1), position2int(11, 2), position2int(11, 3), position2int(11, 4), };  

//使用时可以查询棋子位置是否在行营、山界、大本营里，铁路线或者公路线上（不在铁路线，就在公路线），unordered_set采用哈希表设置，查询时间复杂度近似O（1）
//***.count() == 0? 用法可以百度