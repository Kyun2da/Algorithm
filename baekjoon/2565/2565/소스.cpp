// lis ���� �� �����ϴ� �κм����� Ȱ���� �����ε�
// ���⼭ �������� ������ �ּ� ���� �������� ���� - ���� �� �����ϴ� �κм����� ���� �ȴ�.

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int n, dp[101], dp_max;
	pair <int, int> wire[101]; //�迭�� �������� ���۰� ���������� ���Ѵ�

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wire[i].first >> wire[i].second;
	}

	sort(wire, wire + n+1); //�迭�� �������� ���������� ������ �����Ѵ�
	/*for (int j = 1; j <= n; j++)
	{
		cout << wire[j].first << " " << wire[j].second << endl;
	}*/

	dp[1] = 1;
	for (int i = 2; i <= n; i++) //�迭�� ���������� ���� �� �����ϴ� �κм����� ���Ѵ�.
	{
		dp_max = 0;
		for (int j = 1; j < i; j++)
		{
			if (wire[j].second < wire[i].second && dp_max < dp[j])
				dp_max = dp[j];
		}
		dp[i] = dp_max + 1;
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}*/
	
	cout << n-*max_element(dp+1, dp + n + 1); //�������� ���� - ����� �����ϴ� �κм����� ������ ������ �������� �ּ� ������ �ȴ�.
	return 0;
}