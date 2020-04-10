/**
* @file			Chessboard.h
* @brief        Chessboard�������ͷ�ļ�
* @details		Chessboard����Ҫ�Ǵ洢�������е���Ϣ����
* @author       Bay
* @date			2020.04.08
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.08, �����ĵ�\n
*/
#pragma once
#include "utils.h"
/**
 * ���ӵ��ƶ���ʽ
 * movable		�����ƶ�
 * inmovable	�����ƶ�
 * sapper		����
 */
enum MOVABILITY {
	movable,
	inmovable,
	sapper
};

/**
 * ���ӵ�����
 * flag		����
 * landmine	����
 * dynamite	ը��
 * troop	����
 */
enum TYPE {
	flag,
	landmine,
	dynamite,
	troop
};

/**
 * ��Ӫ
 * B	�ڷ�
 * R	�췽
 */
enum SIDE {
	B,
	R
};
/**
 * ������
 * ����
 *	priority	���ӵ����ȼ�
 *	movability	���ӵ��ƶ���ʽ
 *	type
 */
class Chess
{
public:
	int priority = 0;/// �����ӵ����ȼ� 0Ϊ������������ӣ�������������Ӵ�1��ʼ����
	MOVABILITY movablity;/// �����ӵ��ƶ���ʽ
	TYPE type;/// �����ӵ�����
	SIDE side;/// �����ӵ���Ӫ
	/**
	 * ���캯��
	 * Chess��Ĺ��캯��
	 * @param[in]   chess	��������ӵ�����
	 * @param[out]  outArgName output argument description.
	 * @retval  OK  �ɹ�
	 * @retval  ERROR   ����
	 * @par ��ʶ��
	 *      ����
	 * @par ����
	 *      ��
	 * @par History:
	 *      Bay 2020.04.08 ����\n
	 */
	Chess(char name)
	{
		CASE cas;
		check_case(name, cas);/// ���side
		if (cas == upper)
			side = R;
		else if (cas == lower)
			side = B;
		else
			throw "�����Ӳ��Ǵ�д��Сд��ĸ";
		to_lower_case(name);/// �����Сд�����ڴ���
		switch (name) {
		case 'f':///����
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

	}



};

class Chessboard
{
	/**
	 * ���캯��
	 * Chessboard��Ĺ��캯��
	 * @param[in]   inArgName input argument description.
	 * @param[out]  outArgName output argument description.
	 * @retval  OK  �ɹ�
	 * @retval  ERROR   ����
	 * @par ��ʶ��
	 *      ����
	 * @par ����
	 *      ��
	 * @par History:
	 *      Bay 2020.04.08 ����\n
	 */
	Chessboard();
};

