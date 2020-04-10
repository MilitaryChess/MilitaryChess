/**
* @file			utils.h
* @brief        ���ߺ���������
* @details		���ߺ���
* @author       Bay
* @date			2020.04.10
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.10, �����ĵ�\n
*/
#pragma once
/**
 * ������״̬
 * OK		����˳��
 * ERROR	���г���
 * OVERFLOW	�������
 */
enum STATUS
{
	OK,
	ERROR,
	OVRFLW
};

/**
 * UPPER	��д��ĸ
 * LOWER	Сд��ĸ
 * OTHER	������ĸ
 */
enum CASE {
	upper,
	lower,
	other
};

/**
 * check_case
 * ȷ���Ƿ����ĸΪ��д��Сд����������
 * @param[in]   letter	�������ĸ
 * @param[out]  &retval	CASE���ͣ�������ĸ������
 * @retval  OK  �ɹ�
 * @retval  ERROR   ����
 * @par History:
 *      Bay 2020.04.10 ����\n
 */
STATUS check_case(char letter, CASE &retval);

/**
 * to_lower_case
 * ����ĸת��ΪСд��ĸ
 * @param[in]   &letter	�������ĸ
 * @retval  OK  �ɹ�
 * @retval  ERROR   ����
 * @par History:
 *      Bay 2020.04.10 ����\n
 */
STATUS to_lower_case(char &letter);
