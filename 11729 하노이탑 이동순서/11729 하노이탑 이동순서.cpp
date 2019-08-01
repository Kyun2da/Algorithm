#include <stdio.h>
#include <math.h>
void move(int a, int b)
{
	printf("%d %d\n", a, b);
}
void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		move(from, to);
	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	int number = pow(2, num) - 1;
	printf("%d\n", number);
	hanoi(num, 1, 2, 3);
	return 0;
}