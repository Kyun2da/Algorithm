// lis 가장 긴 증가하는 부분수열을 활용한 문제인데
// 여기서 전깃줄을 제외할 최소 수는 전깃줄의 개수 - 가장 긴 증가하는 부분수열의 수가 된다.

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int n, dp[101], dp_max;
	pair <int, int> wire[101]; //배열을 전깃줄의 시작과 끝지점으로 정한다

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wire[i].first >> wire[i].second;
	}

	sort(wire, wire + n+1); //배열의 전깃줄의 시작점으로 정렬을 수행한다
	/*for (int j = 1; j <= n; j++)
	{
		cout << wire[j].first << " " << wire[j].second << endl;
	}*/

	dp[1] = 1;
	for (int i = 2; i <= n; i++) //배열의 끝지점으로 가장 긴 증가하는 부분수열을 구한다.
	{
		dp_max = 0;
		for (int j = 1; j < i; j++)
		{
			if (wire[j].second < wire[i].second && dp_max < dp[j])
				dp_max = dp[j];
		}
		dp[i] = dp_max + 1;
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}*/
	
	cout << n-*max_element(dp+1, dp + n + 1); //전깃줄의 개수 - 가장긴 증가하는 부분수열의 갯수가 제외할 전깃줄의 최소 개수가 된다.
	return 0;
}