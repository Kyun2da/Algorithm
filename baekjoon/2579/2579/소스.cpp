//����� ������ġ�� ���ִٰ� ������ �� ��ĭ������ ���� ����� ��ĭ������ ���� ������ִ�.
//�� �� ��ĭ ���������°��� ��ĭ�������� ���� �ȵǹǷ� ������ġ�� ��ġ+��ĭ ����ġ�� ��ġ+��ĭ�������� ���� ��� ��ġ��� �� �� �ִ�.
//�� ĭ ���������°��� ������ġ�� ��ġ + ��ĭ ����ġ ������ ���� ��� ��ġ��� �� �� �ִ�.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, num;
	int stair[301];
	int total[301];

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		stair[i] = num;
	}

	total[1] = stair[1];
	total[2] = stair[1] + stair[2];
	total[3] = stair[3] + max(stair[1], stair[2]);

	for (int i = 4; i <= N; i++)
	{
		total[i] = max(stair[i] + stair[i - 1] + total[i - 3], stair[i] + total[i - 2]);
	}

	cout << total[N] << endl;

	return 0;
}