#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001], dp[1001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, ans = 0, num;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
		
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i-1; j++) {
			if (arr[j] < arr[i] && dp[i] < arr[i] + dp[j])
				dp[i] = arr[i] + dp[j];
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	
	cout << ans;

}