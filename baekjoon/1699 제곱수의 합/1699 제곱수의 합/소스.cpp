#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int num = 1;
	int pow_num = 2;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = i;
	for (int i = 2; i <= N; i++) {
		if (pow_num * pow_num == i) {
			dp[i] = 1;
			pow_num++;
			continue;
		}
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << "\n";
	return 0;
}