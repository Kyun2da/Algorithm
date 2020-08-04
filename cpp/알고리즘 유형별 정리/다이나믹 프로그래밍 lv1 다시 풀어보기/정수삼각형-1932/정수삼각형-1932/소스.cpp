#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501], dp[501][501];
int main()
{
	

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1) //���� �밢��
			{
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			}
			else if (j == i) //������ �밢��
			{
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			}
			else //�� �𼭸� �밢���� ������ ������
			{
				dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << *max_element(dp[n]+1, dp[n]+n+1);
	return 0;
}