/**
* @file			Chessboard.h
* @brief        Chessboard类的声明头文件
* @details		Chessboard类主要是存储着棋盘中的信息的类
* @author       niey
* @date			2020.04.10
* @version		0.0.2
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.08, 创建文档\n
*   0.0.2: niey, 2020.04.10, 创建文档\n
*/
#pragma once
#include "utils.h"#pragma once
#include <utility>
using namespace std;

/**
 * 棋格的类型
 * kStation		兵站
 * kCamp		行营
 * kBaseCamp	大本营
 * kMountain	山界
 */
enum CheckType {
	kStation,
	kCamp,
	kBaseCamp,
	kMountain
};

/**
 * 路线的类型
 * kNone		用于没有路线时的赋值
 * kHighway		公路线
 * kRailway		铁路线
 */
enum WayType {
	kNone,
	kHighway,
	kRailway
};
/**
 * 是否可以移动
 * movable		可以移动
 * inmovable	不能移动
 * sapper		工兵
 */
enum MOVABILITY {
	movable,
	inmovable,
	sapper
};

/**
 * 棋子类型
 * flag		军旗
 * landmine	地雷
 * dynamite	炸弹
 * troop	军队
 */
enum TYPE {
	flag,
	landmine,
	dynamite,
	troop
};

/**
 * 阵营
 * B	黑方
 * R	红方
 */
enum SIDE {
	B,
	R
};
/**
 *	棋子类
 *	属性
 *	priority	优先级
 *	movability	是否可以移动
 *	type		棋子种类
 */
class Chess
{
public:
	int priority = 0;/// 棋子的优先级 0代表特殊 其余数字越高优先级越高
	MOVABILITY movablity;/// 是否可以移动
	TYPE type;/// 棋子类型
	SIDE side;/// 棋子的阵营
	/**
	 * 构造函数
	 * Chess类的构造函数
	 * @param[in]   name	棋子的名字
	 * @param[out]  outArgName output argument description.
	 * @par History:
	 *      Bay 2020.04.08 创建\n
	 */
	Chess(char name)
	{
		CASE cas;
		check_case(name, cas);/// 检查side
		if (cas == upper)
			side = R;
		else if (cas == lower)
			side = B;
		else
			throw "不合法的棋子名称";
		to_lower_case(name);/// 为了方便将棋子转为小写
		switch (name) {
		case 'f':/// 军旗
			priority = 0;
			movablity = inmovable;
			type = flag;
			break;
		case 'd':/// 地雷
			priority = 0;
			movablity = inmovable;
			type = landmine;
			break;
		case 'z':/// 炸弹
			priority = 0;
			movablity = movable;
			type = dynamite;
			break;
		case 'g':/// 工兵
			priority = 1;
			movablity = sapper;
			type = troop;
			break;
		case 'p':/// 排长
			priority = 2;
			movablity = movable;
			type = troop;
			break;
		case 'l':/// 连长
			priority = 3;
			movablity = movable;
			type = troop;
			break;
		case 'y':/// 营长
			priority = 4;
			movablity = movable;
			type = troop;
			break;
		case 't':/// 团长
			priority = 5;
			movablity = movable;
			type = troop;
			break;
		case 'v':/// 旅长
			priority = 6;
			movablity = movable;
			type = troop;
			break;
		case 's':/// 师长
			priority = 7;
			movablity = movable;
			type = troop;
			break;
		case 'j':/// 军长
			priority = 8;
			movablity = movable;
			type = troop;
			break;
		case 'a':/// 司令
			priority = 9;
			movablity = movable;
			type = troop;
			break;
		}

	}



};

/**
 * 某个方向上路线的信息
 * is_pass		该方向是否有路线
 * way_type		路线的类型
 */
struct Way {
	bool is_pass;
	WayType way_type;
};

/**
 * 棋格类
 * type_		棋格类型
 * up			正上方向的路线信息
 * down			正下方向的路线信息
 * left			正左方向的路线信息
 * right		正右方向的路线信息
 * left_up		左上方向的路线信息
 * right_up		右上方向的路线信息
 * left_down	左下方向的路线信息
 * right_down	右下方向的路线信息
 */
class Check
{
protected:
	CheckType type_;
	Way up;
	Way down;
	Way left;
	Way right;
	Way left_up;
	Way right_up;
	Way left_down;
	Way right_down;
public:
	Check(pair<char, int> pos)
	{
		if (pos.first == 'a' && (pos.second == 1 || pos.second == 3)) { /// 红方大本营
			type_ = kBaseCamp;
			up = { true, kHighway };
			down = { false, kNone };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'm' && (pos.second == 1 || pos.second == 3)) { /// 黑方大本营
			type_ = kBaseCamp;
			up = { false, kNone };
			down = { true, kHighway };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k')
			&& (pos.second == 1 || pos.second == 3)) { /// 红、黑方行营
			type_ = kCamp;
			up = { true, kHighway };
			down = { true, kHighway };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { true, kHighway };
			right_up = { true, kHighway };
			left_down = { true, kHighway };
			right_down = { true, kHighway };
		}
		else if (pos.first == 'a' && pos.second == 0) { /// 红方最底左边兵站
			type_ = kStation;
			up = { true, kHighway };
			down = { false, kNone };
			left = { false, kNone };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'a' && pos.second == 2) { /// 红方最底中间兵站
			type_ = kStation;
			up = { true, kHighway };
			down = { false, kNone };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'a' && pos.second == 4) { /// 红方最底右边兵站
			type_ = kStation;
			up = { true, kHighway };
			down = { false, kNone };
			left = { true, kHighway };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'm' && pos.second == 0) { /// 黑方最底左边兵站
			type_ = kStation;
			up = { false, kNone };
			down = { true, kHighway };
			left = { false, kNone };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'm' && pos.second == 2) { /// 黑方最底中间兵站
			type_ = kStation;
			up = { false, kNone };
			down = { true, kHighway };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'm' && pos.second == 4) { /// 黑方最底右边兵站
			type_ = kStation;
			up = { false, kNone };
			down = { true, kHighway };
			left = { true, kHighway };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k') && pos.second == 2
			|| (pos.first == 'd' || pos.first == 'j') && (pos.second == 1 || pos.second == 3)
			) { /// 红、黑方夹在行营间的兵站 c2, d1, d3, e2, i2, j1, j3, k2
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kHighway };
			left = { true, kHighway };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'b' && pos.second == 0) { /// 红方兵站 b0
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kHighway };
			left = { false, kNone };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { true, kHighway };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'b' || pos.first == 'l') && (pos.second == 1 || pos.second == 3)) { /// 红方兵站 b1, b3 黑方兵站 l1, l3
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'b' && pos.second == 2) { /// 红方兵站 b2
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { true, kHighway };
			right_up = { true, kHighway };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'b' && pos.second == 4) { /// 红方兵站 b4
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { false, kNone };
			left_up = { true, kHighway };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'l' && pos.second == 0) { /// 黑方兵站 l0
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { true, kHighway };
		}
		else if (pos.first == 'l' && pos.second == 2) { /// 黑方兵站 l2
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { true, kHighway };
			right_down = { true, kHighway };
		}
		else if (pos.first == 'l' && pos.second == 4) { /// 黑方兵站 l4
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kRailway };
			left = { true, kRailway };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { true, kHighway };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k')
			&& pos.second == 0) { /// 红、黑方兵站 c0, e0, i0, k0
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k')
			&& pos.second == 4) { /// 红、黑方兵站 c4, e4, i4, k4
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { true, kHighway };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 0) { /// 红、黑方兵站 d0, j0
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { true, kHighway };
			left_up = { false, kNone };
			right_up = { true, kHighway };
			left_down = { false, kNone };
			right_down = { true, kHighway };
		}
		else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 4) { /// 红、黑方兵站 d4, j4
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { true, kHighway };
			right = { false, kNone };
			left_up = { true, kHighway };
			right_up = { false, kNone };
			left_down = { true, kHighway };
			right_down = { false, kNone };
		}
		else if (pos.first == 'f' && pos.second == 0) { /// 红方兵站 f0
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { true, kHighway };
		}
		else if (pos.first == 'f' && pos.second == 2) { /// 红方兵站 f2
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { true, kHighway };
			right_down = { true, kHighway };
		}
		else if (pos.first == 'f' && pos.second == 4) { /// 红方兵站 f4
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { true, kRailway };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { true, kHighway };
			right_down = { false, kNone };
		}
		else if (pos.first == 'f' && (pos.second == 1 || pos.second == 3)) { /// 红方兵站 f1, f3
			type_ = kStation;
			up = { false, kNone };
			down = { true, kHighway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'h' && pos.second == 0) { /// 黑方兵站 h0
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { true, kHighway };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'h' && pos.second == 2) { /// 黑方兵站 h2
			type_ = kStation;
			up = { true, kHighway };
			down = { true, kRailway };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { true, kHighway };
			right_up = { true, kHighway };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'h' && pos.second == 4) { /// 黑方兵站 h4
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { true, kRailway };
			right = { false, kNone };
			left_up = { true, kHighway };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'h' && (pos.second == 1 || pos.second == 3)) { /// 黑方兵站 h1, h3
			type_ = kStation;
			up = { true, kHighway };
			down = { false, kNone };
			left = { true, kRailway };
			right = { true, kRailway };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'g' && (pos.second == 0 || pos.second == 2 || pos.second == 4)) { /// 前线
			type_ = kStation;
			up = { true, kRailway };
			down = { true, kRailway };
			left = { false, kNone };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else if (pos.first == 'g' && (pos.second == 1 || pos.second == 3)) { /// 山界
			type_ = kStation;
			up = { false, kNone };
			down = { false, kNone };
			left = { false, kNone };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
		else { /// 其他
			type_ = kStation;
			up = { false, kNone };
			down = { false, kNone };
			left = { false, kNone };
			right = { false, kNone };
			left_up = { false, kNone };
			right_up = { false, kNone };
			left_down = { false, kNone };
			right_down = { false, kNone };
		}
	}
};


class Chessboard
{
	/**
	 * 棋盘信息
	 * Chessboard类的构造函数
	 * @param[in]   inArgName input argument description.
	 * @param[out]  outArgName output argument description.
	 * @par History:
	 *      Bay 2020.04.08 创建\n
	 */
	Chessboard();
};