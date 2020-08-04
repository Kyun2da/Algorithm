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
			stair[idx] = i; // 삼각형의 층수, 맨위가 1층
			idx++;
		}
	}

	total[1] = triangle[1]; // 1층의 합은 그대로 합
		
	for (int i = 2; i <= N * (N + 1) / 2; i++)
	{
		left_edge = stair[i] * (stair[i] - 1) / 2 + 1;
		right_edge = stair[i] * (stair[i] + 1) / 2;
		if (i == left_edge) 
		{ //삼각형의 왼쪽모서리이면 왼쪽위의 모서리의 토탈을 그냥 더해주면 됨
			total[i] = triangle[i] + total[(stair[i] - 1) * (stair[i] - 2) / 2 + 1];
		}
		else if (i == right_edge)
		{ //삼각형의 오른쪽모서리이면 위의 모서리의 토탈을 그냥 더해주면 됨
			total[i] = triangle[i] + total[(stair[i] - 1) * (stair[i]) / 2];
		}
		else //나머지는 위의왼쪽과 오른쪽중 더 큰거로 결정
		{
			total[i] = triangle[i] + max(total[i - stair[i]], total[i - stair[i] + 1]);
		}
	}

	for (int i = N * (N - 1) / 2 + 1; i <= N * (N + 1) / 2; i++) //맨 마지막 층 중에서 최대의 합을 찾음
	{
		if (max_num < total[i])
		{
			max_num = total[i];
		}
	}

	cout << max_num << endl;
	return 0;
}