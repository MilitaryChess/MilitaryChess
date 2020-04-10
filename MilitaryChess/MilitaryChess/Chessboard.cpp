/**
* @file			Chessboard.cpp
* @brief        Chessboard类的实现文件
* @details		内容包括Chessboard类中的各种函数
* @author       Bay
* @date			2020.04.08
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.08, 创建文档\n
*	0.0.2: Bay, 2020.04.10, 增加Chessboard构造函数\n
*/
#include "Chessboard.h"
#include "utils.h"

STATUS Chess::assign(char name)
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
	return OK;
}

STATUS Check::assign(pair<char, int> pos)
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
	return OK;
}

Chessboard::Chessboard()
{
	set_chessboard();
}

STATUS Chessboard::set_chessboard()
{
	for (int r = 0; r < 13; r++) {
		for (int c = 0; c < 5; c++) {
			chessboard[r][c].position = make_pair('m' - r, c);
			chessboard[r][c].chess.assign(chessboard[r][c].position.first);
			chessboard[r][c].check.assign(chessboard[r][c].position);
		}
	}
	return OK;
}
