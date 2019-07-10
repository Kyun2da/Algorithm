#include <stdio.h>

int main()
{
	int max = 0;
	int num;
	int order;
	for (int i = 1; i <= 9; i++)
	{
		scanf("%d", &num);
		if (num > max)
		{
			max = num;
			order = i;
		}
	}

	printf("%d %d", max, order);
	return 0;
}