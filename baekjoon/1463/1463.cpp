#include <stdio.h>
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main()
{
	int n, i;
	int dp[1000001];
	scanf("%d", &n);
	dp[0],dp[1] = 0; //dp[0]과 dp[1]은 0이기때문에 미리 써줌 점화식의 초항
	for (i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = MIN(dp[i], dp[i / 2]+1);
		if (i % 3 == 0) dp[i] = MIN(dp[i], dp[i / 3] + 1);
	}
	printf("%d", dp[n]);
	return 0;
}