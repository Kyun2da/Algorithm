//각 배열마다 arr의 인덱스의 긴 부분 수열을 구한다
//1 5 2 1 4 3 4 5 2 1 - 배열 예시
//1 2 2 1 3 3 4 5 2 1 - 왼쪽부터 오른쪽으로의 부분수열 길이
//1 5 2 1 4 3 3 3 2 1 - 오른쪽부터 왼쪽으로의 부분수열 길이
//1 6 3 1 6 5 6 7 3 1 - 위의 두개에서 1을 빼면 다음과 같이 가장 긴 바이토닉 수열의 길이를 찾을 수 있다.

#include <iostream>

using namespace std;

int main() {
	int N;
	int a[1001];
	int dp[1001];
	int dp2[1001];
	int dp_max2 = 0;
	int dp_max = 0;
	int answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	//왼쪽부터 오른쪽의 부분수열 길이를 찾는 식
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp_max = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dp_max < dp[j]) { //비교하고자하는 배열보다 크면 그 곳의 dp값보다는 커야한다는 것
				dp_max = dp[j];
			}
		}
		dp[i] = dp_max + 1;
	}

	dp2[N] = 1;
	for (int i = N-1; i >= 1; i--) {
		dp_max2 = 0;
		for (int j = N; j > i; j--) {
			if (a[j] < a[i] && dp_max2 < dp2[j]) {
				dp_max2 = dp2[j];
			}
		}
		dp2[i] = dp_max2 + 1;
	}

	for (int i = 1; i <= N; i++) {
		if (answer < dp[i] + dp2[i]-1) //dp 두개를 더해 1을 뺀것이 답이 된다.
			answer = dp[i]+dp2[i]-1;
	}

	cout << answer;
	return 0;
}