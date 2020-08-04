#include <iostream>

using namespace std;

int arr[1001][1001];

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j])%10007;
		}
	}

	cout << arr[N][K] << endl;
	return 0;
}