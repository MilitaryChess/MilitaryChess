#pragma once
#include"tools.h"
#include<string>
#include<unordered_set>
using namespace std;
/*�������ݻ�������ļ�Ҫ˵��
���������̵Ĵ���
array<array<int, 5>, 13>������������
���ִ������ӣ�Ҳ��������ӵ����ȼ������˫�������ֵ������ű�ʾ

���ڴ�Ӫ����Ӫ��ɽ�磬��·������·��������һϵ��ȫ�ֳ�����unorder_set�洢��***ֻ��Ҫ�洢һ�Σ��������ڴ�����***
ʹ��ʱֻ��Ҫ��ѯ if (XINGYING.count(position(x,y) != 0) �ͱ�����x��y)��������Ӫ
                 if (RAILWAY.count(position(x,y) != 0) �ͱ�����x��y)��������·
				 position(x,y)���Լ�д�ĺ�����ʹ��ʱ��Ҫ����ͷ�ļ�"tools.h",�����ѣ�x,y)ת��Ϊint,��Ϊunordered_set������pair<int,int>����
����unorder_set���ڲ���������ڹ�ϣ�����Բ�ѯ��ʱ�临�Ӷ�ԼΪO��1��

�������������ĸ�������·��
1.ֻ�д�Ӫ����8��������·
2.���м���һ��ֻ������2������
3.���඼�������̷�Χ�������4������
*/
//ppdfd / plldz / z3y / yt1ty / s1g1s / jvgva / 5 / JVGVA / S1G1S / YT1TY / Z1G1Y / PLLDZ / PPDFD
//��Ӧ
/*
 -5  -5  -2  -1  -2
 -5  -6  -6  -2  -3
 -3   0   0   0  -7
 -7  -8   0  -8  -7
-10   0  -4   0 -10
-11  -9  -4  -9 -12
  0   0   0   0   0
 11   9   4   9  12
 10   0   4   0  10
  7   8   0   8   7
  3   0   4   0   7
  5   6   6   2   3
  5   5   2   1   2
*/
struct Chess {//������
	string name;//����
	int num;//���ȼ�
	int n;//������
};
const int BLANK = 0;  // �հ�
const int FLAG = 1;  // ����
const int DI = 2; //����
const int ZHA = 3;  // ը��
const int GONG = 4;  // ����
const int PAI = 5;  // �ų�
const int LIAN = 6;  // ����
const int YING = 7;  // Ӫ��
const int TUAN = 8;  // �ų�
const int LV = 9;  // �ó�
const int SHI = 10;  // ʦ��
const int JUN = 11;  // ����
const int SI = 12;  // ˾��

const Chess CHESS[13] = {
	Chess{"BLANK", 0, -1},
		Chess{"FLAG", 1, 1},
		Chess{"DI", 2, 3},
		Chess{"ZHA", 3, 2},
		Chess{"GONG", 4, 3},
		Chess{"PAI", 5, 3},
		Chess{"LIAN", 6, 3},
		Chess{"YING", 7, 2},
		Chess{"TUAN", 8, 2},
		Chess{"LV", 9, 2},
		Chess{"SHI", 10, 2},
		Chess{"JUN", 11, 1},
		Chess{"SI", 12, 1}
};

//[0,13]
//�����ڷ��ų��ı���ֵ = B * pai�� �췽�����ı���ֵ = R * jun
const int B = 1; //�Է��ڷ���д��ĸ
const int R = -1; //�����췽Сд��ĸ

//�����½�Ϊԭ��
//��Ӫ����
const unordered_set<int> XINGYING = { position2int(2, 1), position2int(2, 3), position2int(3, 2), position2int(4, 1), position2int(4, 3), position2int(8, 1),
position2int(8, 3), position2int(9, 2), position2int(10, 1), position2int(10, 3) };  

//ɽ������
const unordered_set<int> SHANJIE = { position2int(6, 1), position2int(6, 3) };  

//��Ӫ����
const unordered_set<int> DABENYING = { position2int(0, 1), position2int(0, 3), position2int(12, 1), position2int(12, 3) };  

//��·������
const unordered_set<int> RAILWAY = { position2int(1, 0), position2int(1, 1), position2int(1, 2), position2int(1, 3), position2int(1, 4),
position2int(2, 0),position2int(2, 4),position2int(3, 0),position2int(3, 4),position2int(4, 0),position2int(4, 4),
position2int(5, 0), position2int(5, 1), position2int(5, 2), position2int(5, 3), position2int(5, 4),
position2int(6, 0),position2int(6, 2),position2int(6, 4),
position2int(7, 0), position2int(7, 1), position2int(7, 2), position2int(7, 3), position2int(7, 4),
position2int(8, 0), position2int(8, 4), position2int(9, 0), position2int(9, 4), position2int(10, 0),position2int(10, 4),
position2int(11, 0), position2int(11, 1), position2int(11, 2), position2int(11, 3), position2int(11, 4), };  

//ʹ��ʱ���Բ�ѯ����λ���Ƿ�����Ӫ��ɽ�硢��Ӫ���·�߻��߹�·���ϣ�������·�ߣ����ڹ�·�ߣ���unordered_set���ù�ϣ�����ã���ѯʱ�临�ӶȽ���O��1��
//***.count() == 0? �÷����԰ٶ�