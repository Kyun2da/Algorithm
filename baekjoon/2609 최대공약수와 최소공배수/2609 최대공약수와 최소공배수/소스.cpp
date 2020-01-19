#include <iostream>

using namespace std;

int main()
{
	int a, b,c, lcm,gcd;

	cin >> a >> b;
	lcm = a * b;
	while (b > 0)
	{
		c = b;
		b = a % b;
		a = c;
	}
	gcd = a;

	lcm = lcm / gcd;

	cout << gcd << endl << lcm << endl;

	return 0;
}