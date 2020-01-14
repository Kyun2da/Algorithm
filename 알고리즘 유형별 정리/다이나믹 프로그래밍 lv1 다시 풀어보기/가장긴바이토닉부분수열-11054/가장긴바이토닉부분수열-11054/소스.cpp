//이문제는 11053문제를 왼쪽으로 한번 오른쪽으로 한번 더해준다고 생각하면 쉽다.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, dp_max, arr[1001], dp1[1001], dp2[1001], dp3[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp1[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp_max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && dp_max < dp1[j])
				dp_max = dp1[j];
		}
		dp1[i] = dp_max + 1;
	}

	dp2[n] = 1;
	for (int i = n-1; i >= 1; i--)
	{
		dp_max = 0;
		for (int j = n; j >= i; j--)
		{
			if (arr[i] > arr[j] && dp_max < dp2[j])
				dp_max = dp2[j];
		}
		dp2[i] = dp_max + 1;
	}

	for (int i = 1; i <= n; i++)
		dp3[i] = dp1[i] + dp2[i];
	cout << *max_element(dp3 + 1, dp3 + n + 1)-1 << endl;

	return 0;
}