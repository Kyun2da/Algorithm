#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = num-1; i > 0; i--)  //À­ÁÙ
	{
		for (int j = i; j > 0; j--)
			printf(" ");
		for (int k = -2*i+(num*2-1); k >0; k--)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < num; i++) //¾Æ·§ÁÙ
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int k = 2 * num - (2 * i + 1); k > 0; k--)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;
}