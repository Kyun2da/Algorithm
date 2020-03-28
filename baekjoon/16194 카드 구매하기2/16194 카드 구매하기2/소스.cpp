#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];
int dp[10001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i]; //dp[i]를 초기의 해당팩을 살때의 돈으로 생각

		for (int j = i - 1; j >= i / 2; j--)
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
	}
	cout << dp[N];
	return 0;
}