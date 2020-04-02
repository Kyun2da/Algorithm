#include <iostream>

using namespace std;

#define mod 1000000009

long long int dp[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= mod;
	}
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}