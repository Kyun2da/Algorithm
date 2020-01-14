//top-down 접근방식을 이용
//맨마지막 계단은 무조건 건너야하므로 n-1계단을 건너는 방법과 n-1계단을 안건너는 방법이 있다.
//1. 먼저 n-1 계단을 건너면 n-2계단은 건너면안된다. 여기서 dp(n-1)이라고 생각하면 안되는 것은 dp(n-1)의 마지막계단과 마지막 전계단을 건너게되면 
//세칸을 연속해서 건너는 것이기 때문에 n-2계단은 건너선 안되는 것이다. 따라서 n계단 n-1계단 건너고 n-2계단 건너고 n-3을 건너야하는데 여기서 n-3의 전계단은
//건너도 영향이 없으므로 이 방법은 dp(n-3)과 arr[n-1]+arr[n]이라고 할 수 있겠다.

//2. n-1계단을 안건너면 n-2계단은 무조건 건너야한다.
//이 방법은 arr[n] + dp[n-2]라고 할 수 있다.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,arr[301],dp[301];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1], dp[2] = arr[1] + arr[2], dp[3] = max(arr[1], arr[2]) + arr[3];

	for (int i = 4; i <= n; i++)
	{
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3] + arr[i - 1]);
	}

	cout << dp[n] << endl;
	return 0;
}