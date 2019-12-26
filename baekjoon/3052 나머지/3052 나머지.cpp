#include <stdio.h>

int main()
{
	int a;
	int namugi[10];
	int namugiNum = 0;
	int jungbok = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a);
		namugi[i]= a % 42;		
	}
	for (int j = 0; j < 10; j++)
	{
		for (int k = j-1; k >= 0; k--)
		{
			if (namugi[j] == namugi[k])
			{
				jungbok = 1;
				break;
			}
		}
		if (jungbok == 0)
			namugiNum += 1;
		jungbok = 0;
	}
	printf("%d", namugiNum);
	return 0;
}