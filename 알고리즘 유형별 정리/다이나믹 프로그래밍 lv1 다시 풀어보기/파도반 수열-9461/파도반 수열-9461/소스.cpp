//여기에는 두가지 점화식이 있다
// 1. DP[n] = DP[n-2] + DP[n-3]
// 2. DP[n] = DP[n-1] + DP[n-5]
#include <iostream>

using namespace std;
int main()
{
	long long arr[101];
	int n, num;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	cin >> n;
	while (n--)
	{
		cin >> num;
		cout << arr[num] << endl;
	}


	return 0;
}