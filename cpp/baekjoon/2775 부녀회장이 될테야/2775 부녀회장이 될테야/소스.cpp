#include <stdio.h>

int main()
{
	int n[15][15]; //[รþ][ศฃ], 0รþบฮลอ14รþ,1ศฃบฮลอ14ศฃ
	for (int i = 1; i <= 14; i++)
	{
		n[i][1] = 1;
		n[0][i] = i;
	}

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 2; j <= 14; j++) 
		{
			n[i][j] = n[i - 1][j] + n[i][j - 1];
		}
	}

	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", n[a][b]);
	}
	return 0;
}