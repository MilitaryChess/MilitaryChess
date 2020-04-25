#include<iostream>
#include "common.h"
#include"tools.h"
using namespace std;

/**
* @file			test.cpp
* @brief        ����ncn������ת��
* @param[in]    Ncn��
* @param[out]   ��ӡ����״̬��û���ӵ�λ��Ϊ0�����ӵ�λ����ʾ�ڲ������ֵ����Ӫ��*���
* @author       ssc
* @date			2020.04.18
* @version		0.0.1
*/
void test_ncn(const char s[])
{
	LBChess t;
	int a = 0, b = 0;
	t.parse_ncn(s, a, b);
	t.seetheboard();
}

/**
* @file			test.cpp
* @brief        �������ӿ��Դﵽ��λ��
* @param[in]    Ncn��
* @param[out]   ��ӡ����״̬�������������ڵ�λ����*����������ߵ�λ����1�����ܵ���λ����0
* @author       ssc
* @date			2020.04.20
* @version		0.0.1
*/
void test_move(const int row, const int col, const char s[])
{
	LBChess t;
	vector<pair<int,int>>res;
	int a = 0, b = 0;
	t.parse_ncn(s, a, b);//����ncn��ת��������
	t.seetheboard();//��ʾ�����ʽ
	cout << endl << endl;
	res = t.get(make_pair(row, col));//�õ����Ե���λ�ã�����res
	char r[13][5] ;
	int i, j;
	for (i = 0; i < 13; i++)
		for (j = 0; j < 5; j++)
			r[i][j] = '0';
	r[row][col] = '*';//����һ����ά���飬��ʼȫ��0��Ȼ��ǰλ����*
	for (auto p = res.begin(); p != res.end(); p++)
		r[(*p).first][(*p).second] = '1';//���ص�vector�ж�Ӧ��λ�ã��ڶ�ά��������1
	//��ӡ��ά����
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 5; j++)
			cout << r[i][j] << "  ";
		cout << endl;
	}
}
int main()
{
	test_move(2,1,"5/1Pg2/1gg11/212/s1g11/jvg11/5/JVGVA/S1G1S/YT1TY/Z1G1Y/PLLDZ/PPDFD");
}