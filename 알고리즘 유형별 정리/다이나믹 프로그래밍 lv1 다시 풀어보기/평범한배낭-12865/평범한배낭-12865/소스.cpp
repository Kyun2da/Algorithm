#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int dp[101][100001];
int main()
{
	int n, k; // n: 물품의수, k:버틸수있는무게
	pair <int, int> item[101];

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i].first >> item[i].second; //first는 아이템의 무게, second는 아이템의 가치
	}

	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	
	sort(item, item + n + 1);

	/*for (int i = 0; i <= n; i++)
		cout << "( " << item[i].first << ", " << item[i].second << " )";*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (item[i].first > j) //아이템의 무게가 가방의 무게보다 크다면
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(item[i].second + dp[i-1][j - item[i].first], dp[i - 1][j]);
		}
	}


	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << dp[n][k] << endl;

	return 0;
}