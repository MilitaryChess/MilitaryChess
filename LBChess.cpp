#include"common.h"
#include<array>
#include <queue>
#include <vector>
#include <iomanip>
/**
* @file			LBChess.cpp
* @brief        �ж��Ƿ����
* @param[in]    ��������
* @param[out]   ����;ַ���0�����򷵻�Ӯ��R����-1��B����1�����û�н�������2
* @author       zzh
* @date			2020.04.13
* @version		0.0.1
*/
int if_end(const array<array<int, 5>, 13>& board)
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



bool LBChess::tie(int x, int y) {
	return(x >= 0 && y >= 0 && x <= 12 && y <= 4 && _tie[x][y] == 1);
}

/**
* @file       LBChess.cpp
* @brief      �����ƶ�������յ㣬�޸�����board�����ж�����һ��������Ƿ����
* @author     zjx
* @date        2020.4.25
* @param[in]   start_end_point   ������յ�����
* @param[out]  ����;ַ���0�����򷵻�Ӯ��R����-1��B����1�����û�н�������2
* @par history
		zjx��2020.4.25����\n
*/
int LBChess::modify_board(pair<pair<int, int>, pair<int, int>> start_end_point) {
	int result = attack(board[start_end_point.first.first][start_end_point.first.second],
		board[start_end_point.second.first][start_end_point.second.second]);
	if (result == -1)
		board[start_end_point.first.first][start_end_point.first.second] = BLANK;
	else if(result==0)
	{
		board[start_end_point.first.first][start_end_point.first.second] = BLANK;
		board[start_end_point.second.first][start_end_point.second.second] = BLANK;
	}
	else {
		board[start_end_point.second.first][start_end_point.second.second] = board[start_end_point.first.first][start_end_point.first.second];
		board[start_end_point.first.first][start_end_point.first.second] = BLANK;
	}
	return if_end(board);
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
		SHANJIE.count(position2int(pos.first, pos.second)))  //[��Ӫ�޷��ƶ����������]
		return result;
	//��·�ߣ�������Χ�˸�λ��
	for (int i = -1; i < 2; i++)
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
			if (board[new_row][new_col] != 0 && board[pos.first][pos.second] != 0 && board[new_row][new_col] * board[pos.first][pos.second] > 0)
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
			if (tie(new_pos.first, new_pos.second) && board[new_pos.first][new_pos.second] == BLANK)
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

/**
* @file			LBChess.cpp
* @brief        ������·���ϣ��������Ե��������λ��
* @param[in]    ����λ��pair<int, int>, ���Ե���λ�õ�vector�����ô���
* @param[out]   ��(���Ե���λ�õķ��������õ�vector����
* @author       ssc
* @date			2020.04.14
* @version		0.0.2
*/
void LBChess::_get_gong(pair<int, int>pos, vector<pair<int, int>>& res)
{
	/*����˼·��ʹ��BFS����Ѱ·�������һ��λ���Ǽ��������Ѿ�̽�������ǹ�·�ߣ���ֹͣ̽��
	 �������·�ߣ��������У��ȴ�����
	 �Ӷ����г����У�����������������
	*/
	//cout <<"testget_gong   "<< pos.first << "  " << pos.second << endl;
	int group;//�������ķ���Ӫ
	//if (RAILWAY.count(position2int(pos.first, pos.second)) == 0 || abs(board[pos.first][pos.second]) != GONG) //����·�߻���û�й����򷵻�
		//return;
	if (board[pos.first][pos.second] > 0)
		group = 1;
	else
		group = -1;//��֤��������*group>0,�Է���*group<0
	int temp[13][5] = {
		{0, 0, 0, 0, 0},
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
		{0, 0, 0, 0, 0} };//������·�ߵ�ͼ��Ϊ�˼ӿ������ٶ�
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 5; j++)
		{
			if (temp[i][j] == 0)
				continue;
			if (board[i][j] * group > 0)
				temp[i][j] = -1;//�Լ�����-1
			if (board[i][j] * group < 0)
				temp[i][j] = 2;//������2
		}//���õ�ͼ����·��λ����0����·�߿հ׵ط�Ϊ0���Լ�λ��Ϊ1������λ��Ϊ2

	vector<pair<int, int>>result;
	/*cout << "testget_gong   " << endl;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 5; j++)
			cout << temp[i][j]<<"  ";
		cout << endl;
	}*/
	queue<pair<int, int>> Q;
	Q.push(pos);
	pair<int, int> current, a;//��ʱ��������¼���ڵ�λ��
	while (Q.size() > 0)
	{
		current = Q.front();
		Q.pop();//�����У�Ȼ���¼
		//cout << "testget_gong   " << current.first << "  " << current.second << endl;
		result.push_back(current);//����result�У���������ߵ�
		temp[current.first][current.second] = -1;//�����ѷ��ʹ�
		if (current.first + 1 < 13) {
			if (temp[current.first + 1][current.second] == 1)
				Q.push(make_pair(current.first + 1, current.second));//�������·��������У������´η���
			else if (temp[current.first + 1][current.second] == 2)
				result.push_back(make_pair(current.first + 1, current.second));//����ǵ��ˣ��Ϳ����ߵ����λ�ã����ܼ���
			//����ǹ�·�������������Ѿ�̽���������
		}
		if (current.second + 1 < 5) {
			if (temp[current.first][current.second + 1] == 1)
				Q.push(make_pair(current.first, current.second + 1));
			else if (temp[current.first][current.second + 1] == 2)
				result.push_back(make_pair(current.first, current.second + 1));
		}
		if (current.first - 1 >= 0) {
			if (temp[current.first - 1][current.second] == 1)
				Q.push(make_pair(current.first - 1, current.second));
			else if (temp[current.first - 1][current.second] == 2)
				result.push_back(make_pair(current.first - 1, current.second));
		}
		if (current.second - 1 >= 0) {
			if (temp[current.first][current.second - 1] == 1)
				Q.push(make_pair(current.first, current.second - 1));
			else if (temp[current.first][current.second - 1] == 2)
				result.push_back(make_pair(current.first, current.second - 1));
		}
	}
	result.erase(result.begin());//��һ��Ԫ���Ǵ����pos,�Ƴ�
	res.insert(res.end(), result.begin(), result.end());
	unique(res.begin(), res.end());
	//cout << "testget_gong   " << result.size() << endl;
}

/**
* @file			LBChess.cpp
* @brief        �鿴���̵�ǰ״̬
* @param[in]    /
* @param[out]   ��ӡ����״̬��û���ӵ�λ��Ϊ0�����ӵ�λ����ʾ�ڲ������ֵ����Ӫ��*���
* @author       ssc
* @date			2020.04.18
* @version		0.0.1
*/
void LBChess::seetheboard()
{
	int i, j;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 5; j++)
		{
			if (XINGYING.count(position2int(i, j)) > 0)
				cout << setw(4) << "*" << board[i][j] << "*";
			else
				cout << setw(5) << board[i][j];
		}
		cout << endl;
	}
}