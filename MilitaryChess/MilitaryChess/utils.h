/**
* @file			utils.h
* @brief        工具函数的声明
* @details		工具函数
* @author       Bay
* @date			2020.04.10
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.10, 创建文档\n
*/
#pragma once
/**
 * 函数的状态
 * OK		运行顺利
 * ERROR	运行出错
 * OVERFLOW	运行溢出
 */
enum STATUS
{
	OK,
	ERROR,
	OVRFLW
};

/**
 * UPPER	大写字母
 * LOWER	小写字母
 * OTHER	其他字母
 */
enum CASE {
	upper,
	lower,
	other
};

/**
 * check_case
 * 确认是否该字母为大写、小写或其他类型
 * @param[in]   letter	输入的字母
 * @param[out]  &retval	CASE类型，返回字母的类型
 * @retval  OK  成功
 * @retval  ERROR   错误
 * @par History:
 *      Bay 2020.04.10 创建\n
 */
STATUS check_case(char letter, CASE &retval);

/**
 * to_lower_case
 * 将字母转换为小写字母
 * @param[in]   &letter	输入的字母
 * @retval  OK  成功
 * @retval  ERROR   错误
 * @par History:
 *      Bay 2020.04.10 创建\n
 */
STATUS to_lower_case(char &letter);
