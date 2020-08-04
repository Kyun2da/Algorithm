#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001],dp[1001], N,sum=0;

	cin >> N;

	for (int i = 1; i <= N; i++) 
		cin >> arr[i];

	sort(arr + 1, arr + N + 1);

	dp[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i] = arr[i] + dp[i - 1];
	}

	for (int i = 1; i <= N; i++)
		sum += dp[i];

	cout << sum << endl;
	return 0;
}