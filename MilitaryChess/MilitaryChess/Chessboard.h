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
#include "utils.h"
#include <utility>
#include <iostream>
using namespace std;

/**
 * 棋格的类型
 * kStation		兵站
 * kCamp		行营
 * kBaseCamp	大本营
 * kMountain	山界
 */
enum class CheckType {
	kStation,
	kCamp,
	kBaseCamp,
	kMountain
};

/**
 * 重载CheckType输出
 * 重载CheckType输出运算符以查看CheckType类型
 * @param[in]   out		输出流，C		枚举类型CheckType
 * @param[out]  out		输出流
 * @par History:
 *      nie-y 2020.04.10 创建\n
 */
inline ostream& operator<<(ostream& out, const CheckType& C) {
	switch (C) {
		case CheckType::kStation:
			out << "S";
			break;
		case CheckType::kCamp:
			out << "C";
			break;
		case CheckType::kBaseCamp:
			out << "B";
			break;
		case CheckType::kMountain:
			out << "M";
			break;
	}
	return out;
}

/**
 * 路线的类型
 * kNone		用于没有路线时的赋值
 * kHighway		公路线
 * kRailway		铁路线
 */
enum class WayType {
	kNone,
	kHighway,
	kRailway
};

/**
 * 重载WayType输出
 * 重载WayType输出运算符以查看WayType类型
 * @param[in]   out		输出流，W		枚举类型WayType
 * @param[out]  out		输出流
 * @par History:
 *      nie-y 2020.04.10 创建\n
 */
inline ostream& operator<<(ostream& out, const WayType& W) {
	switch (W) {
	case WayType::kNone:
		cout << " ";
		break;
	case WayType::kHighway:
		out << ".";
		break;
	case WayType::kRailway:
		out << "*";
		break;
	}
	return out;
}

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
	/**
	 * 赋值函数
	 * 给Check类的数据成员赋值
	 * @param[in]   pos		棋格的位置坐标
	 * @param[out]  None
	 * @par History:
	 *      nie-y 2020.04.10 创建\n
	 */
	void assign(pair<char, int> pos)
	{
		if (pos.first == 'a' && (pos.second == 1 || pos.second == 3)) { /// 红方大本营
			type_ = CheckType::kBaseCamp;
			up = { true, WayType::kHighway };
			down = { false, WayType::kNone };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'm' && (pos.second == 1 || pos.second == 3)) { /// 黑方大本营
			type_ = CheckType::kBaseCamp;
			up = { false, WayType::kNone };
			down = { true, WayType::kHighway };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k') && (pos.second == 1 || pos.second == 3)
			|| (pos.first == 'd' || pos.first == 'j') && pos.second == 2) { /// 红、黑方行营
			type_ = CheckType::kCamp;
			up = { true, WayType::kHighway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { true, WayType::kHighway };
			right_up = { true, WayType::kHighway };
			left_down = { true, WayType::kHighway };
			right_down = { true, WayType::kHighway };
		}
		else if (pos.first == 'a' && pos.second == 0) { /// 红方最底左边兵站
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { false, WayType::kNone };
			left = { false, WayType::kNone };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'a' && pos.second == 2) { /// 红方最底中间兵站
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { false, WayType::kNone };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'a' && pos.second == 4) { /// 红方最底右边兵站
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { false, WayType::kNone };
			left = { true, WayType::kHighway };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'm' && pos.second == 0) { /// 黑方最底左边兵站
			type_ = CheckType::kStation;
			up = { false, WayType::kNone };
			down = { true, WayType::kHighway };
			left = { false, WayType::kNone };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'm' && pos.second == 2) { /// 黑方最底中间兵站
			type_ = CheckType::kStation;
			up = { false, WayType::kNone };
			down = { true, WayType::kHighway };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'm' && pos.second == 4) { /// 黑方最底右边兵站
			type_ = CheckType::kStation;
			up = { false, WayType::kNone };
			down = { true, WayType::kHighway };
			left = { true, WayType::kHighway };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k') && pos.second == 2
			|| (pos.first == 'd' || pos.first == 'j') && (pos.second == 1 || pos.second == 3)
			) { /// 红、黑方夹在行营间的兵站 c2, d1, d3, e2, i2, j1, j3, k2
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kHighway };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'b' && pos.second == 0) { /// 红方兵站 b0
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kHighway };
			left = { false, WayType::kNone };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { true, WayType::kHighway };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'b' || pos.first == 'l') && (pos.second == 1 || pos.second == 3)) { /// 红方兵站 b1, b3 黑方兵站 l1, l3
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'b' && pos.second == 2) { /// 红方兵站 b2
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { true, WayType::kHighway };
			right_up = { true, WayType::kHighway };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'b' && pos.second == 4) { /// 红方兵站 b4
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { false, WayType::kNone };
			left_up = { true, WayType::kHighway };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'l' && pos.second == 0) { /// 黑方兵站 l0
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { true, WayType::kHighway };
		}
		else if (pos.first == 'l' && pos.second == 2) { /// 黑方兵站 l2
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { true, WayType::kHighway };
			right_down = { true, WayType::kHighway };
		}
		else if (pos.first == 'l' && pos.second == 4) { /// 黑方兵站 l4
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kRailway };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { true, WayType::kHighway };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k')
			&& pos.second == 0) { /// 红、黑方兵站 c0, e0, i0, k0
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'c' || pos.first == 'e' || pos.first == 'i' || pos.first == 'k')
			&& pos.second == 4) { /// 红、黑方兵站 c4, e4, i4, k4
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kHighway };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 0) { /// 红、黑方兵站 d0, j0
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { true, WayType::kHighway };
			left_up = { false, WayType::kNone };
			right_up = { true, WayType::kHighway };
			left_down = { false, WayType::kNone };
			right_down = { true, WayType::kHighway };
		}
		else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 4) { /// 红、黑方兵站 d4, j4
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kHighway };
			right = { false, WayType::kNone };
			left_up = { true, WayType::kHighway };
			right_up = { false, WayType::kNone };
			left_down = { true, WayType::kHighway };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'f' && pos.second == 0) { /// 红方兵站 f0
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { true, WayType::kHighway };
		}
		else if (pos.first == 'f' && pos.second == 2) { /// 红方兵站 f2
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { true, WayType::kHighway };
			right_down = { true, WayType::kHighway };
		}
		else if (pos.first == 'f' && pos.second == 4) { /// 红方兵站 f4
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kRailway };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { true, WayType::kHighway };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'f' && (pos.second == 1 || pos.second == 3)) { /// 红方兵站 f1, f3
			type_ = CheckType::kStation;
			up = { false, WayType::kNone };
			down = { true, WayType::kHighway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'h' && pos.second == 0) { /// 黑方兵站 h0
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { true, WayType::kHighway };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'h' && pos.second == 2) { /// 黑方兵站 h2
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { true, WayType::kHighway };
			right_up = { true, WayType::kHighway };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'h' && pos.second == 4) { /// 黑方兵站 h4
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { true, WayType::kRailway };
			right = { false, WayType::kNone };
			left_up = { true, WayType::kHighway };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'h' && (pos.second == 1 || pos.second == 3)) { /// 黑方兵站 h1, h3
			type_ = CheckType::kStation;
			up = { true, WayType::kHighway };
			down = { false, WayType::kNone };
			left = { true, WayType::kRailway };
			right = { true, WayType::kRailway };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'g' && (pos.second == 0 || pos.second == 2 || pos.second == 4)) { /// 前线
			type_ = CheckType::kStation;
			up = { true, WayType::kRailway };
			down = { true, WayType::kRailway };
			left = { false, WayType::kNone };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else if (pos.first == 'g' && (pos.second == 1 || pos.second == 3)) { /// 山界
			type_ = CheckType::kMountain;
			up = { false, WayType::kNone };
			down = { false, WayType::kNone };
			left = { false, WayType::kNone };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
		else { /// 其他
			type_ = CheckType::kStation;
			up = { false, WayType::kNone };
			down = { false, WayType::kNone };
			left = { false, WayType::kNone };
			right = { false, WayType::kNone };
			left_up = { false, WayType::kNone };
			right_up = { false, WayType::kNone };
			left_down = { false, WayType::kNone };
			right_down = { false, WayType::kNone };
		}
	}
	
	/**
	 * 输出函数
	 * 输出Check类数据成员的值，主要用于测试/调试
	 * @param[in]   None
	 * @param[out]  None
	 * @par History:
	 *      nie-y 2020.04.10 创建\n
	 */
	void output1()
	{
		cout << left_up.way_type  << " " << up.way_type << " " << right_up.way_type << " ";
	}
	void output2()
	{
		cout << left.way_type << " " << type_ << " " << right.way_type << " ";
	}
	void output3()
	{
		cout << left_down.way_type << " " << down.way_type << " " << right_down.way_type << " ";
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