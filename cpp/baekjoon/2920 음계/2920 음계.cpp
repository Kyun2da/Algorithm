#include <stdio.h>

int main()
{
	int a[8];
	int ascendingNum=0, descendingNum=0;
	for (int i = 0; i < 8; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < 8; j++)
	{
		if (a[j] == j + 1)
			ascendingNum += 1;
		else if (a[j] == 8 - j)
			descendingNum += 1;
	}
	if (ascendingNum == 8)
		printf("ascending");
	else if (descendingNum == 8)
		printf("descending");
	else
		printf("mixed");

	return 0;
}