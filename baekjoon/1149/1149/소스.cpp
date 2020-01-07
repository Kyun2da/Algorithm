#include <iostream>
#include <algorithm>
using namespace std;
//�������α׷���
//������ ���� ��� ĥ�ϴ��Ŀ� ���� �ּڰ��� �ٸ���. ������ ���� ĥ�� ���� 3���߿� ���� ���� ���� ���ϸ� �ȴ�.
//3��° ���� ������ ĥ�ߴٸ� �ι�° ĥ�� ���� �ʷϻ��� �ּڰ��� �Ķ����� �ּڰ��� ���� ���� ���ϸ� �ȴ�. �װ��� 3��° ���� ������ ĥ���� ���� �ּڰ��̴�.
//ù��° ���� �ִٰ� �����ϸ� �� ���� �ּڰ��� �׳� ù��° ���� ���� ����� ���򸶴��� �ּ� ����� �ȴ�.
//�ι�° ���� ������ ĥ�ϸ� �� �ּڰ��� min(ù��°���� �ʷ��� ĥ������, ù��° ���� �Ķ���ĥ������)+�ι�°���� ��������� �ּڰ��� �ȴ�.
// �̷������� �����غ��� �ᱹ ���� ���� ���򸶴��� �ּڰ��� min(n-1���� �ٸ� �� ������ ��) + ���� ���� ���� ��� �̵ȴ�.
int main()
{
	int house_num, color_table[1001][3], r, g, b, total_table[1001][3];

	cin >> house_num;

	for (int i = 1; i <= house_num; i++)
	{
		cin >> r >> g >> b;
		color_table[i][0] = r;
		color_table[i][1] = g;
		color_table[i][2] = b;
	}

	total_table[1][0] = color_table[1][0];
	total_table[1][1] = color_table[1][1];
	total_table[1][2] = color_table[1][2];

	for (int i = 2; i <= house_num; i++)
	{
		total_table[i][0] = min(total_table[i - 1][1], total_table[i - 1][2]) + color_table[i][0];
		total_table[i][1] = min(total_table[i - 1][2], total_table[i - 1][0]) + color_table[i][1];
		total_table[i][2] = min(total_table[i - 1][0], total_table[i - 1][1]) + color_table[i][2];
	}

	cout << min(total_table[house_num][0], min(total_table[house_num][1], total_table[house_num][2])) << endl;
	return 0;
}