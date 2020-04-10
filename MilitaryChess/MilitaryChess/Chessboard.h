/**
* @file			Chessboard.h
* @brief        Chessboard类的声明头文件
* @details		Chessboard类主要是存储着棋盘中的信息的类
* @author       Bay
* @date			2020.04.08
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.08, 创建文档\n
*/
#pragma once
#include "utils.h"
/**
 * 棋子的移动方式
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
 * 棋子的类型
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
 * 棋子类
 * 属性
 *	priority	棋子的优先级
 *	movability	棋子的移动方式
 *	type
 */
class Chess
{
public:
	int priority = 0;/// 该棋子的优先级 0为特殊种类的棋子，军队种类的棋子从1开始排序
	MOVABILITY movablity;/// 该棋子的移动方式
	TYPE type;/// 该棋子的类型
	SIDE side;/// 该棋子的阵营
	/**
	 * 构造函数
	 * Chess类的构造函数
	 * @param[in]   chess	输入的棋子的名称
	 * @param[out]  outArgName output argument description.
	 * @retval  OK  成功
	 * @retval  ERROR   错误
	 * @par 标识符
	 *      保留
	 * @par 其它
	 *      无
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
			throw "该棋子不是大写或小写字母";
		to_lower_case(name);/// 都变成小写，便于处理
		switch (name) {
		case 'f':///军旗
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

class Chessboard
{
	/**
	 * 构造函数
	 * Chessboard类的构造函数
	 * @param[in]   inArgName input argument description.
	 * @param[out]  outArgName output argument description.
	 * @retval  OK  成功
	 * @retval  ERROR   错误
	 * @par 标识符
	 *      保留
	 * @par 其它
	 *      无
	 * @par History:
	 *      Bay 2020.04.08 创建\n
	 */
	Chessboard();
};

