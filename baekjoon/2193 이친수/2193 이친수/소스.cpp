#include <iostream>
using namespace std;
//DP 문제
//피보나치 문제와 동일하다는 것을 규칙을 통해 확인할 수 있다.
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