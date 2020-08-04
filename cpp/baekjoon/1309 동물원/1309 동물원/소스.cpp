#include <iostream>

using namespace std;

long long int dp[100001];
#define mod 9901 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= 100000; i++) {
		dp[i] = dp[i - 1] * 2 + dp[i - 2];
		dp[i] %= mod;
	}
	int N;
	cin >> N;

	cout << dp[N] << "\n";

	return 0;
}