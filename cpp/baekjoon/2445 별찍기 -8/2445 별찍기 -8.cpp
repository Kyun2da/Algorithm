#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) //����
	{
		for (int j = 0; j <=i; j++)
		{
			printf("*");
		}
		for (int k = 0; k < 2 * (num - 1) - (i * 2); k++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < num - 1; i++) //�Ʒ���
	{
		for (int j = 0; j < num-i-1; j++)
		{
			printf("*");
		}
		for (int k = 0; k < 2 * (i+1); k++)
		{
			printf(" ");
		}
		for (int j = 0; j < num - i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}