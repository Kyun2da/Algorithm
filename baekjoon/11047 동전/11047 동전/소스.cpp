#include <iostream>

using namespace std;

int main()
{
	int N, K, arr[11],sum=0;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	while (K != 0)
	{
		if (K / arr[N] != 0) //ū������ �������� ���� ������
		{
			sum += K / arr[N];
			K = K % arr[N];
		}
		N--;
	}

	cout << sum << endl;
	return 0;
}