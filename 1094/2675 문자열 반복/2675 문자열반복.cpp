#include <stdio.h>

int main()
{
	int caseNum;
	int num;
	char s[21];
	scanf("%d", &caseNum);
	for (int i = 0; i < caseNum; i++)
	{
		scanf("%d %s", &num,s);
		int k = 0;
		while (s[k] != '\0')
		{
			for (int j = 0; j < num; j++)
				printf("%c", s[k]);
			k++;
		}
		printf("\n");
	}

	return 0;
}