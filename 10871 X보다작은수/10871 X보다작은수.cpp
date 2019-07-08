#include <stdio.h>

int main()
{
	int num;
	int compare;
	int a;
	scanf("%d %d", &num,&compare);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a);
		if (a < compare)
			printf("%d ", a);
	}

	return 0;
}