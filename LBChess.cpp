#include"common.h"
#include<array>
/**
* @file			LBChess.cpp
* @brief        �ж��Ƿ����
* @param[in]    ��������
* @param[out]   ����;ַ���0�����򷵻�Ӯ��R����-1��B����1�����û�н�������2
* @author       zzh
* @date			2020.04.13
* @version		0.0.1
*/
int end(const array<array<int, 5>, 13>& board)
{
	//�жϾ����Ƿ񱻳�
	bool FlagR = false, FlagB = false;
	//�ж��Ƿ���ڿ����ƶ�������
	bool live_R = false, live_B = false;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == FLAG)//B��������R�Ǹ���
				FlagB = true;
			else if (board[i][j] == -FLAG)
				FlagR = true;
			else if (board[i][j] >= 3 && board[i][j] <= 12)
				live_B = true;
			else if (board[i][j] <= -3 && board[i][j] >= -12)
				live_R = true;
		}
	if (!FlagB)  return R;
	if (!FlagR)  return B;
	if (!live_B && !live_R)//�;�
		return 0;
	if (live_B && live_R)//δ����
		return 2;
	return live_B ? B : R;
}


/**
* @file			LBChess.cpp
* @brief        �������ӵȼ��жϹ������
* @param[in]    src : ������ dst : ����Ŀ��
* @param[out]   ͬ���ھ�����0�������ɹ�����1������ʧ�ܷ��� - 1
* @author       zzh
* @date			2020.04.13
* @version		0.0.1
*/
int attack(int src, int dst)
{
	if (abs(src) == DI || abs(src) == FLAG || src * dst >= 0) // �����߲����ǵ��׻�����հף�˫��������ͬһ��ɫ�����򱨴�
		cout << "�Ƿ��Ĺ�����" << endl;
	src = abs(src); dst = abs(dst);
	if (dst == ZHA or src == ZHA)  // ը����Ȼͬ���ھ�
		return 0;
	if (dst == DI)  // �����ŵ��ף�����ͬ���ھ�
		return src == GONG ? 1 : 0;
	if (src == dst)  // ��ͬ��ͬ���ھ�
		return 0;
	if (dst == FLAG)  // ��������
		return 1;
	return src > dst ? 1 : -1;
}

/*
LBChess�ࣺ
ά��������Ϣ
ȷ�����ӺͲ������ȷ��
ȷ����������ȷ��
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
class LBChess//������ 
{
private:
	array<array<int, 5>, 13> board;
public:
	LBChess() { board = {}; };//ȫ��
	LBChess(const array<array<int, 5>, 13>& data) { board = data; };
	//move����
	//get����
	//__get__gong����
};