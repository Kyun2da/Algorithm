#include <iostream>
#define mod 10007
using namespace std;

// dp문제 10844와 비슷한 문제
int main()
{
	int dp[1001][10] = { 0 };

	for (int i = 0; i <= 9; i++)  
		dp[1][i] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) 
	{
		for (int j = 0; j <= 9; j++) 
		{
			for (int k = 0; k <= j; k++) 
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += dp[n][i];

	cout << sum%mod;
	return 0;
}