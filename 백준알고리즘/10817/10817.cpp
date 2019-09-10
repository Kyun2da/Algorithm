#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a >= b)
	{
		if (a >= c)
		{
			if (b >= c)
			{
				printf("%d", b);
			}
			else
				printf("%d", c);
		}
		else if (a < c)
		{
			printf("%d", a);
		}
	}
	else if (a < b)
	{
		if (a < c)
		{
			if (b >= c)
			{
				printf("%d", c);
			}
			else if (b < c)
			{
				printf("%d", b);
			}
		}
		else if (a >= c)
		{
			printf("%d", a);
		}
	}
	return 0;
}