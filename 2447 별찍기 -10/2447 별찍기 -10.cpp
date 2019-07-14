#include <stdio.h>
#include <stdlib.h>
//분할 정복을 사용하는 문제 
char **mat;

void solve(int y, int x, int num)
{
	if (num == 1)
	{
		mat[y][x] = '*';
		return;
	}

	int div = num / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 1 || j != 1)
				solve(y + (i*div), x + (j*div), div);
		}
	}
}
int main()
{
	int k;
	scanf("%d", &k);
	mat = (char**)malloc(sizeof(char*) * k);
	for (int i = 0; i < k; i++) {
		mat[i] = (char*)malloc(sizeof(char) * k);
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
			mat[i][j] = ' ';
	}
	solve(0, 0, k);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}
}