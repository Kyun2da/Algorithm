#include <iostream>

using namespace std;

int main()
{
	long long int a, b, c, n;
	cin >> n;

	a = 0;
	b = 1;
	c = 1;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	cout << c;
	return 0;
}