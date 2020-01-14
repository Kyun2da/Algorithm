//이 아이디어는 전깃줄을 앞의 선 번호로 정렬한뒤에 
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> arr[101];
	int n,dp_max,dp[101];

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr + 1, arr + n + 1);

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp_max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i].second > arr[j].second && dp_max < dp[j])
				dp_max = dp[j];
		}
		dp[i] = dp_max + 1;
	}

	cout << n - *max_element(dp + 1, dp + n + 1) << endl;
	return 0;
}