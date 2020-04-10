/**
* @file			utils.cpp
* @brief        ���ߺ���
* @details		���ߺ���
* @author       Bay
* @date			2020.04.10
* @version		0.0.1
* @par Copyright (c):
*       MilitaryChess
* @par History:
*   0.0.1: Bay, 2020.04.10, �����ĵ�\n
*/
#include "utils.h"
STATUS check_case(char letter, CASE& retval)
{
	if (letter >= 'A' && letter <= 'Z')
		retval = upper;
	else if (letter >= 'a' && letter <= 'z')
		retval = lower;
	else
		retval = other;
	return OK;
}

STATUS to_lower_case(char& letter)
{
	if (letter >= 'A' && letter <= 'Z')
		letter += 32;
	return OK;
}