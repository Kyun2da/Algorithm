/*
dp_max에 해당원소에 도착할때까지 최대의 원소 값을 저장해 놓는다
해당원소보다 작은 수이고 저장해놓은 dp_max보다 크다면 dp_max를 작은 수의 dp값으로 교체한다
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int dp_max,arr[1001],dp[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp_max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && dp_max < dp[j])
				dp_max = dp[j];
		}
		dp[i] = dp_max + 1;
	}

	cout << *max_element(dp+1,dp+n+1) << endl;
	return 0;
}