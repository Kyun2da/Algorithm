/*
dp_max�� �ش���ҿ� �����Ҷ����� �ִ��� ���� ���� ������ ���´�
�ش���Һ��� ���� ���̰� �����س��� dp_max���� ũ�ٸ� dp_max�� ���� ���� dp������ ��ü�Ѵ�
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int dp_max,arr[1001],dp[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp_max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && dp_max < dp[j])
				dp_max = dp[j];
		}
		dp[i] = dp_max + 1;
	}

	cout << *max_element(dp+1,dp+n+1) << endl;
	return 0;
}