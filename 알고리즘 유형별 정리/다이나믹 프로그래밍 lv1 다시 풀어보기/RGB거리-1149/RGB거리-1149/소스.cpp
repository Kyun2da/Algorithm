//각 집의 Dp는 전의 집까지 그린 것의 이웃하는 집이 아닌 색깔의 최소값+ 현재 집의 색값이다
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001][3], DP[1001][3], n;

	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	DP[1][0] = arr[1][0], DP[1][1] = arr[1][1], DP[1][2] = arr[1][2];

	for (int i = 2; i <= n; i++)
	{
		DP[i][0] = arr[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] = arr[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
		DP[i][2] = arr[i][2] + min(DP[i - 1][1], DP[i - 1][0]);
	}

	cout << min(min(DP[n][0], DP[n][1]), DP[n][2]);

	return 0;
}