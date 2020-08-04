//타일을 맨뒤를 1로하면 n-1개의 개수가 있는것 타일의 맨뒤를 0으로하면 그앞도 0이 되어야하므로 n-2개의 개수가 있는것
// 따라서 n의 타일수는 n-1 + n-2 개의 타일 수이다
#include <iostream>

using namespace std;
int arr[10000001];
int main()
{
	int n;
	arr[1] = 1;
	arr[2] = 2;

	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	cout << arr[n];
	return 0;
}