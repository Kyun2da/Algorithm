#include <iostream>
using namespace std;
//DP ����
//�Ǻ���ġ ������ �����ϴٴ� ���� ��Ģ�� ���� Ȯ���� �� �ִ�.
int main()
{
	
	int n;
	long long x[91];
	x[1] = 1; x[2] = 1;
	cin >> n;
	for (int i = 3; i <= n; i++)
		x[i] = x[i - 1] + x[i - 2];

	cout << x[n];
	return 0;
}