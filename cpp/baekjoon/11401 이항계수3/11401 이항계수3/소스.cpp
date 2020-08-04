// 페르마의 소정리
//https://cru6548.tistory.com/23
#include <iostream>

using namespace std;


long long int fac[4000001];

int main()
{
	int N, K;
	cin >> N >> K;
	
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i % 1000000007;
	long long int bVal = fac[K] * fac[N - K] % 1000000007;
	int index = 1000000007 - 2;
	long long int resVal = 1;

	while (index > 0)
	{
		if (index % 2)
		{
			resVal *= bVal;
			resVal %= 1000000007;
		}
		bVal = bVal * bVal;
		bVal %= 1000000007;
		index /= 2;
	}
	
	cout << ((fac[N] % 1000000007) * (resVal % 1000000007)) % 1000000007;


	return 0;
}