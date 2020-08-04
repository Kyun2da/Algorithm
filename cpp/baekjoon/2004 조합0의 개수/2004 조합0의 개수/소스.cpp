#include <iostream>
#include <algorithm>

using namespace std;
int twoCount(int n)
{
	int two_num=0;
	
	for (long long int i = 2; i <= n; i*=2)
		two_num += n / i;
	
	return two_num;
}

int fiveCount(int n)
{
	int five_num = 0;

	for (long long int i = 5; i <= n; i *= 5)
		five_num += n / i;

	return five_num;
}
int main()
{
	long long int n, k;
	int two, five;

	cin >> n >> k;

	two = twoCount(n) - twoCount(k) - twoCount(n - k);
	five = fiveCount(n) - fiveCount(k) - fiveCount(n - k);

	cout << min(two, five);

	return 0;
}