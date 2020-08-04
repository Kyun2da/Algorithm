#include <stdio.h>

int main()
{
	int width, height;
	char a[100][100];
	scanf("%d %d", &height, &width);
	for (int i = 0; i < height; i++)
	{
			scanf("%s", &a[i]);
	}
	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}*/

	for (int i = width-1; i >= 0; i--)
	{
		for (int j = 0; j < height; j++)
		{
			if (a[j][i] == '.')
				printf(".");
			else if (a[j][i] == 'O')
				printf("O");
			else if (a[j][i] == '-')
				printf("|");
			else if (a[j][i] == '|')
				printf("-");
			else if (a[j][i] == '/')
				printf("\\");
			else if (a[j][i] == '\\')
				printf("/");
			else if (a[j][i] == '^')
				printf("<");
			else if (a[j][i] == '<')
				printf("v");
			else if (a[j][i] == 'v')
				printf(">");
			else
				printf("^");
		}
		printf("\n");
	}
	return 0;
}