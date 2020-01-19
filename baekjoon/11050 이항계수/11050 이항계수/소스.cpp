#include <iostream>

using namespace std;
int factorial(int a)
{
	if (a == 1 || a==0)
		return 1;

	return a*factorial(a - 1);
}

int main()
{
	int N, K;

	cin >> N >> K;

	cout << factorial(N) / factorial(N - K) / factorial(K);
	
	return 0;
}