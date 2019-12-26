#include <iostream>
using namespace std;
int dp[10001];
int arr[10001];

int max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}
int main()
{
	dp[0] = 0;
	arr[0] = 0;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= num; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1], arr[i] + dp[i - 2]); 
		//포도주가 i-3번째의 합과 i-1과 i번째를 더했을때(i-2번째를 뺀다고 생각)
		//포도주가 i-1번째의 합일때 (i번째를 뺀다고생각)
		//포도주가 i번째와 i-2번째의합을 더했을때 (i-1번째를 뺀다고 생각)
		//4개의 잔이있을때 첫번째 잔이 지금까지의 잔의 합이고 남은 3잔중 어느것을 뺄지를 고민하면 됨
	}
	cout << dp[num];
	return 0;
}