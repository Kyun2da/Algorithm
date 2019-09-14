#include <iostream>
#define mod 1000000000
using namespace std;

//dp문제 쉬운자리수
// 맨끝자리가 0인경우엔 그앞자리가 1일수밖에없다
// 맨끝자리가 9인경우엔 그앞자리가 8일수밖에없다
// 나머지 경우에는 앞뒤 두가지case가 가능하다.
int main()
{
	int num;
	long long sum = 0;
	cin >> num;

	int dp[101][10] ; //100이하의 자릿수이므로

	
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;   //첫째 자리수는 1가지의 수이므로 1로 초기화
	
	for (int i = 2; i <= num; i++) //몇째 자리수까지(n)를 구하느냐 
	{	
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) dp[i][0] = dp[i - 1][1]; //앞자리가 0이면 뒷자리는 1밖에 될수 없으므로
			else if (j == 9) dp[i][9] = dp[i - 1][8]; //앞자리가 9이면 뒷자리는 8밖에 될수 없으므로
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	
	for (int i = 1; i <= 9; i++)
		sum += dp[num][i];

	cout << sum %mod;
	return 0;
}