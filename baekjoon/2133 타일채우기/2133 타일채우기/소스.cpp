#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int dp[31] = { 0 };
	int N;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= 30; i++) {
		if (i % 2 == 1)
			dp[i] = 0;
		else {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = 4; j <= i; j += 2) {
				dp[i] += dp[i - j] * 2; //2는 고유모양
			}
		}
	}
	/*
	for (int i = 1; i <= 30; i++) {
		cout << dp[i] << " ";
	}*/

	cin >> N;
	cout << dp[N];
	


	return 0;
}