#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b > 0)
	{	
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}
int main()
{
	int n, arr[101],g;
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 2; i <= n; i++)
	{
		g = gcd(arr[1], arr[i]);
		cout << arr[1] / g << "/" << arr[i] / g << endl;
	}
	return 0;
}