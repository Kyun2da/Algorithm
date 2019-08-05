#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int k = 0; k < i; k++)
			printf(" ");
		for (int j = 2 * num - 1; j > i * 2; j--)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num-2-i; j++)
		printf(" ");
		for (int k = 0; k < 3+i*2; k++)
			printf("*");
		printf("\n");
	}


	return 0;
}