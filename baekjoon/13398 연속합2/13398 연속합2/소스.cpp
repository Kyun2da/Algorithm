#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001][2];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, ans=0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[0][0] = 0, dp[0][1] = 0;
	dp[1][0] = arr[1], dp[1][1] = arr[1];
	ans = arr[1];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = max(arr[i],arr[i] + dp[i - 1][0]);
		dp[i][1] = max(arr[i],max(dp[i - 2][0] + arr[i], dp[i - 1][1] + arr[i]));
		if (ans < dp[i][1])
			ans = dp[i][1];
	}

	cout << ans;


	return 0;
}