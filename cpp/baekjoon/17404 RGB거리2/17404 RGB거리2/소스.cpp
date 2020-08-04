#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N,temp, ans=1000000;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++) { //빨 초 파로 돌아가면서 계산
		dp[1][0] = 1000000;
		dp[1][1] = 1000000;
		dp[1][2] = 1000000;
		dp[1][i] = arr[1][i];
		for (int j = 2; j <= N; j++) {
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}
		if(i==0)
			temp = min(dp[N][1], dp[N][2]);
		else if (i == 1)
			temp = min(dp[N][0], dp[N][2]);
		else
			temp = min(dp[N][0], dp[N][1]);
		if (ans > temp)
			ans = temp;
	}

	cout << ans;
	return 0;
}