#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int k = 2*num-(2*i+1); k > 0; k--)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;
}