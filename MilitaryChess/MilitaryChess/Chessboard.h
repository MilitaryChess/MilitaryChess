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
#include <array>
#include <string>
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
	 * 赋值函数
	 * Chess类的赋值函数
	 * @param[in]   name	棋子的名字
	 * @param[out]  outArgName output argument description.
	 * @par History:
	 *      Bay 2020.04.08 创建\n
	 */
	STATUS assign(char name);
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
	STATUS assign(pair<char, int> pos);
	
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

/**
 *	PLACE
 *	每个棋盘上的位置的信息
*/
typedef struct {
	pair<char, int> position;
	Chess chess;
	Check check;
} PLACE;

class Chessboard
{
	array<array<PLACE, 5>, 13> chessboard;
	int width = 5;
	int height = 13;
	/**
	 * 构造函数
	 * Chessboard类的构造函数
	 * @param[in]   inArgName input argument description.
	 * @param[out]  outArgName output argument description.
	 * @par History:
	 *      Bay 2020.04.08 创建\n
	 */
	Chessboard();
	/**
	 * 设置棋盘信息
	 * 将棋盘中加入棋盘的信息
	 * @param[in]   inArgName input argument description.
	 * @param[out]  outArgName output argument description.
	 * @par History:
	 *      Bay 2020.04.10 创建\n
	 */
	STATUS set_chessboard();
};