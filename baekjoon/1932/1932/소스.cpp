#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, triangle[150000] = { 0, }, num, total[150000] = { 0, }, idx = 1, stair[150000] = { 0, }, max_num=0;
	int left_edge, right_edge;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> num;
			triangle[idx] = num;
			stair[idx] = i; // �ﰢ���� ����, ������ 1��
			idx++;
		}
	}

	total[1] = triangle[1]; // 1���� ���� �״�� ��
		
	for (int i = 2; i <= N * (N + 1) / 2; i++)
	{
		left_edge = stair[i] * (stair[i] - 1) / 2 + 1;
		right_edge = stair[i] * (stair[i] + 1) / 2;
		if (i == left_edge) 
		{ //�ﰢ���� ���ʸ𼭸��̸� �������� �𼭸��� ��Ż�� �׳� �����ָ� ��
			total[i] = triangle[i] + total[(stair[i] - 1) * (stair[i] - 2) / 2 + 1];
		}
		else if (i == right_edge)
		{ //�ﰢ���� �����ʸ𼭸��̸� ���� �𼭸��� ��Ż�� �׳� �����ָ� ��
			total[i] = triangle[i] + total[(stair[i] - 1) * (stair[i]) / 2];
		}
		else //�������� ���ǿ��ʰ� �������� �� ū�ŷ� ����
		{
			total[i] = triangle[i] + max(total[i - stair[i]], total[i - stair[i] + 1]);
		}
	}

	for (int i = N * (N - 1) / 2 + 1; i <= N * (N + 1) / 2; i++) //�� ������ �� �߿��� �ִ��� ���� ã��
	{
		if (max_num < total[i])
		{
			max_num = total[i];
		}
	}

	cout << max_num << endl;
	return 0;
}