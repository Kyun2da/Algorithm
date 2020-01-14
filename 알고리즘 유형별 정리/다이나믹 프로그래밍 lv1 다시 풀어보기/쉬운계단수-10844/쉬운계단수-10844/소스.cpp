//맨마지막수를 정해놨을때 top-down 접근법으로 가보면된다
//맨마지막수가 0이면 그 앞은 무조건 1이다
//맨마지막수가 9이면 그 앞은 무조건 8이다.
//나머지는 그앞이나 뒤의 수가 될수있다

#include <stdio.h>
#define mod 1000000000
int main(void) {
	int N;
	int dp[101][10] = {};
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % mod;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % mod;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[N][i]) % mod;
	printf("%d\n", sum % mod);
}
