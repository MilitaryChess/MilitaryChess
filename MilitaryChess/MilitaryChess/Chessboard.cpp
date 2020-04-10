/**
* @file			Chessboard.cpp
* @brief        Chessboard���ʵ���ļ�
* @details		���ݰ���Chessboard���еĸ��ֺ���
* @author       Bay
* @date			2020.04.08
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.08, �����ĵ�\n
*	0.0.2: Bay, 2020.04.10, ����Chessboard���캯��\n
*/
#include "Chessboard.h"
#include "utils.h"

STATUS Chess::assign(char name)
{
	CASE cas;
	check_case(name, cas);/// ���side
	if (cas == upper)
		side = R;
	else if (cas == lower)
		side = B;
	else
		throw "���Ϸ�����������";
	to_lower_case(name);/// Ϊ�˷��㽫����תΪСд
	switch (name) {
	case 'f':/// ����
		priority = 0;
		movablity = inmovable;
		type = flag;
		break;
	case 'd':/// ����
		priority = 0;
		movablity = inmovable;
		type = landmine;
		break;
	case 'z':/// ը��
		priority = 0;
		movablity = movable;
		type = dynamite;
		break;
	case 'g':/// ����
		priority = 1;
		movablity = sapper;
		type = troop;
		break;
	case 'p':/// �ų�
		priority = 2;
		movablity = movable;
		type = troop;
		break;
	case 'l':/// ����
		priority = 3;
		movablity = movable;
		type = troop;
		break;
	case 'y':/// Ӫ��
		priority = 4;
		movablity = movable;
		type = troop;
		break;
	case 't':/// �ų�
		priority = 5;
		movablity = movable;
		type = troop;
		break;
	case 'v':/// �ó�
		priority = 6;
		movablity = movable;
		type = troop;
		break;
	case 's':/// ʦ��
		priority = 7;
		movablity = movable;
		type = troop;
		break;
	case 'j':/// ����
		priority = 8;
		movablity = movable;
		type = troop;
		break;
	case 'a':/// ˾��
		priority = 9;
		movablity = movable;
		type = troop;
		break;
	}
	return OK;
}

STATUS Check::assign(pair<char, int> pos)
{
	if (pos.first == 'a' && (pos.second == 1 || pos.second == 3)) { /// �췽��Ӫ
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
	else if (pos.first == 'm' && (pos.second == 1 || pos.second == 3)) { /// �ڷ���Ӫ
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
		&& (pos.second == 1 || pos.second == 3)) { /// �졢�ڷ���Ӫ
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
	else if (pos.first == 'a' && pos.second == 0) { /// �췽�����߱�վ
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
	else if (pos.first == 'a' && pos.second == 2) { /// �췽����м��վ
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
	else if (pos.first == 'a' && pos.second == 4) { /// �췽����ұ߱�վ
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
	else if (pos.first == 'm' && pos.second == 0) { /// �ڷ������߱�վ
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
	else if (pos.first == 'm' && pos.second == 2) { /// �ڷ�����м��վ
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
	else if (pos.first == 'm' && pos.second == 4) { /// �ڷ�����ұ߱�վ
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
		) { /// �졢�ڷ�������Ӫ��ı�վ c2, d1, d3, e2, i2, j1, j3, k2
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
	else if (pos.first == 'b' && pos.second == 0) { /// �췽��վ b0
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
	else if ((pos.first == 'b' || pos.first == 'l') && (pos.second == 1 || pos.second == 3)) { /// �췽��վ b1, b3 �ڷ���վ l1, l3
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
	else if (pos.first == 'b' && pos.second == 2) { /// �췽��վ b2
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
	else if (pos.first == 'b' && pos.second == 4) { /// �췽��վ b4
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
	else if (pos.first == 'l' && pos.second == 0) { /// �ڷ���վ l0
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
	else if (pos.first == 'l' && pos.second == 2) { /// �ڷ���վ l2
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
	else if (pos.first == 'l' && pos.second == 4) { /// �ڷ���վ l4
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
		&& pos.second == 0) { /// �졢�ڷ���վ c0, e0, i0, k0
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
		&& pos.second == 4) { /// �졢�ڷ���վ c4, e4, i4, k4
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
	else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 0) { /// �졢�ڷ���վ d0, j0
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
	else if ((pos.first == 'd' || pos.first == 'j') && pos.second == 4) { /// �졢�ڷ���վ d4, j4
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
	else if (pos.first == 'f' && pos.second == 0) { /// �췽��վ f0
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
	else if (pos.first == 'f' && pos.second == 2) { /// �췽��վ f2
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
	else if (pos.first == 'f' && pos.second == 4) { /// �췽��վ f4
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
	else if (pos.first == 'f' && (pos.second == 1 || pos.second == 3)) { /// �췽��վ f1, f3
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
	else if (pos.first == 'h' && pos.second == 0) { /// �ڷ���վ h0
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
	else if (pos.first == 'h' && pos.second == 2) { /// �ڷ���վ h2
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
	else if (pos.first == 'h' && pos.second == 4) { /// �ڷ���վ h4
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
	else if (pos.first == 'h' && (pos.second == 1 || pos.second == 3)) { /// �ڷ���վ h1, h3
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
	else if (pos.first == 'g' && (pos.second == 0 || pos.second == 2 || pos.second == 4)) { /// ǰ��
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
	else if (pos.first == 'g' && (pos.second == 1 || pos.second == 3)) { /// ɽ��
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
	else { /// ����
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
