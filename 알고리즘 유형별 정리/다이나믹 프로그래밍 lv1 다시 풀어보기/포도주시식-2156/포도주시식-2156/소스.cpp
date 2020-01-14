//top-down방식
//포도주를 맨마지막껄 먹었다고 생각해보았을때, 마지막전꺼를 먹는경우와 먹지않는경우로 다시 두가지로 나눌수 있다
//마지막 전꺼를 먹으면 마지막 전전꺼는 못먹으므로 dp[n-3]+arr[n-1]+arr[n] 이 하나의 방법이된다.
//마지막 전꺼를 먹지않으면 dp[n-2] + arr[n] 이 또다른 방법이 된다.
//마지막꺼를 먹지않는 dp[n-1]이 다른 방법으로 총 3가지 방법중 가장 큰 경우를 고르면 된다
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int arr[10001], dp[10001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], max(arr[1] + arr[2], arr[2]+arr[3]));
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 1],max( arr[i] + arr[i - 1] + dp[i - 3], dp[i - 2] + arr[i]));
	}

	cout << dp[n] << endl;


	return 0;
}