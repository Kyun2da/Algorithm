#include <iostream>

using namespace std;
long long int a, c;
long long int calc(long long int b)
{
	if (b == 0)
		return 1;
	else if (b % 2 == 0)
		return calc(b/2)*calc(b/2) % c;
	else
		return calc(b/2)*calc(b/2)%c * a % c;
}
int main()
{
	long long int A, B, C;
	//A를 B번 곱한수를 C로 나눈 나머지
	cin >> A >> B >> C;
	a = A;
	c = C;
	cout << calc(B);



	return 0;
}