//연속합은 -가 중요한데 이를 어떻게 처리할지가 이 문제의 핵심이다.
//순수하게 dp로 합을 쭉 써내려가다보면 예시의 문제는 값이 dp[i-1]보다 dp[i]가 작은경우, 그리고 dp의 수가 -가되는경우가 있다
//dp[i-1]보다 dp[i]가 작은경우는 단지 dp[i-1]을 택하면 되기때문에 문제 없지만 dp가 -가된다면 뒤의dp에 영향을 끼치기때문에,
//여기서 영향을 끼친다는것은 뒤에부터 시작하는것이 앞의 dp보다 합이 더 높을수 있다는말, 그러므로 dp가-가될때 dp[i+1]
//부터는 다시 arr[i+1]을 처음으로 생각하여 계산하여야 한다.
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];
int main()
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 1] < 0)
			dp[i] = arr[i];
		else
			dp[i] = arr[i] + dp[i - 1];
	}

	cout << *max_element(dp + 1, dp + n + 1) << endl;




	return 0;
}