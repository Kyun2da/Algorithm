#include <stdio.h>

int main()
{
	int max = -1000000;
	int min = 1000000;
	int a;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a);
		if (a >= max)
		{
			max = a;
		}
		if (a <= min)
		{
			min = a;
		}
	}
	printf("%d %d", min, max);
	return 0;
}