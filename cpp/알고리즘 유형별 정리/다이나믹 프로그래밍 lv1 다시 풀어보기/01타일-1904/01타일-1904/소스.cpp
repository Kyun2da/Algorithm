//Ÿ���� �ǵڸ� 1���ϸ� n-1���� ������ �ִ°� Ÿ���� �ǵڸ� 0�����ϸ� �׾յ� 0�� �Ǿ���ϹǷ� n-2���� ������ �ִ°�
// ���� n�� Ÿ�ϼ��� n-1 + n-2 ���� Ÿ�� ���̴�
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