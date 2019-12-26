#include <stdio.h>

int main()
{
	char s[101];
	int number[26] = {0};
	scanf("%s", s);
	for (int k = 0; k <= 25; k++)
	{
		number[k] = -1;
	}
	int i = 0;
	while (s[i] != '\0')
	{
		for (int j = 97; j <= 122; j++)
		{
			if (s[i] == j && number[j-97]==-1)
			{
				number[j - 97] = i;
				break;
			}
		}
		i++;
	}
	for (int k = 0; k <= 25; k++)
	{
		printf("%d ", number[k]);
	}
	return 0;
}