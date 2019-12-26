#include <stdio.h>

int main()
{
	char s[1000001];
	int number[26] = {0,};
	int max = 0;
	int maxNum = -1;
	int jungbok = 0;
	scanf("%s", s);
	int k = 0;
	while (s[k] != '\0')
	{
		for (int i = 97; i <= 122; i++)
		{
			if (s[k] == i || s[k] == i - 32)
				number[i - 97] += 1;
		}
		k++;
	}
	/*for (int k = 0; k <= 25; k++)
	{
		printf("%d ", number[k]);
	}
	printf("\n");*/
	for (int i = 0; i <= 25; i++)
	{
		if (max < number[i])
		{
			max = number[i];
			jungbok = 0;
			maxNum = i;
		}
		else if (max == number[i])
			jungbok = 1;
	}
	if (jungbok == 1)
		printf("?");
	else
		printf("%c", maxNum + 65);
	
	return 0;
}