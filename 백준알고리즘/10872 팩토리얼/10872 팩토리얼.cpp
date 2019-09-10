#include <stdio.h>
int factorial(int n)
{
	int fac = 1;
	for (int i = n; i>=1; i--)
	{
		fac *= i;
	}
	return fac;
}
int main()
{
	int num;
	scanf("%d", &num);
	printf("%d",factorial(num));
	return 0;
}