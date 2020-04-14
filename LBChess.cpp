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
�������������Ϸ����
*/
class LBChess//������ 
{
private:
	array<array<int, 5>, 13> board;
	vector<vector<int>> _tie = {
		{0, 0, 0, 0, 0} ,
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0} };
public:
	LBChess() { board = {}; };//ȫ��
	LBChess(const array<array<int, 5>, 13>& data) { board = data; };
	//move����
	//get����
	//__get__gong����
	vector<pair<int, int>> get(pair<int, int>pos);
	bool tie(int x,int y);   //�Ƿ�����·����
	void _get_gong(pair<int, int> pos, vector<pair<int, int>>& result);
};
bool LBChess::tie(int x,int y) {
	return(x >= 0 && y >= 0 && x <= 12 && y <= 4 && _tie[x][y] == 1);
}

/**
* @file       LBChess.cpp
* @brief      �õ�ĳһλ�����ӿ����ߵ�����λ��
* @author     zjx
* @date        2020.4.14
* @param[in]   pos    λ������
* @param[out]  result   ���пɵ���λ��
* @par history    
		zjx��2020.4.14����\n
*/
vector<pair<int, int>>LBChess::get(pair<int, int>pos) {
	vector<pair<int, int>>result;
	if (abs(board[pos.first][pos.second]) == BLANK || abs(board[pos.first][pos.second]) == FLAG || abs(board[pos.first][pos.second]) == DI ||
		SHANJIE.count(position2int(pos.first, pos.second)) )  //[��Ӫ�޷��ƶ����������]
		return result;
	//��·�ߣ�������Χ�˸�λ��
	for(int i=-1;i<2;i++)
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)
				continue;
			int new_row = pos.first + i;
			int new_col = pos.second + j;
			if (new_row < 0 || new_row>12 || new_col < 0 || new_col>4)    //�����ƶ�������
				continue;
			if (SHANJIE.count(position2int(pos.first, pos.second)))   //�����ƶ���ɽ��
				continue; 
			if (i != 0 && j != 0 && !XINGYING.count(position2int(pos.first, pos.second)) &&
				!XINGYING.count(position2int(new_row, new_col)))//б�������ƶ�������һ������Ӫ
				continue;
			if (XINGYING.count(position2int(new_row, new_col)) && board[new_row][new_col] != BLANK)//����ƶ�����Ӫ����Ӫ������������
				continue;
			result.push_back(make_pair(new_row, new_col));
		}
	
	//��·�ߣ�����ֱ��·��������ǹ�����ʹ�ù�����Ѱ·�㷨
	if (!tie(pos.first, pos.second))
		return result;
	if (abs(board[pos.first][pos.second]) == GONG)
		_get_gong(pos, result);
	else
	{
		int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		for (int i = 0; i < 4; i++) {
			pair<int, int> new_pos = make_pair(pos.first + direct[i][0], pos.second + direct[i][1]);
			if(tie(new_pos.first,new_pos.second)&&board[new_pos.first][new_pos.second]==BLANK)
				while (true) {
					new_pos.first = new_pos.first + direct[i][0];
					new_pos.second = new_pos.second + direct[i][1];
					if (!tie(new_pos.first, new_pos.second))  //����·����
						break;
					if (board[new_pos.first][new_pos.second] * board[pos.first][pos.second] > 0)  //ͬɫ�ڵ�
						break;
					result.push_back(new_pos);
					if (board[new_pos.first][new_pos.second] * board[pos.first][pos.second] < 0)
						break;
				}
		}
	}
	return result;

}