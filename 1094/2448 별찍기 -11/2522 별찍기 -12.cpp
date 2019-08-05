#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = num - i-1; j > 0; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < i + 1; k++)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf(" ");
		for (int j = num - i - 1; j > 0; j--)
			printf("*");
		printf("\n");
	}


	return 0;
}

