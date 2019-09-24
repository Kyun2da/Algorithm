#include <stdio.h>

int main()
{
	int num;
	int x[200], y[200], rank_num[200];
	scanf("%d", &num);
	for(int i=0; i<num; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i < num; i++)
	{
		int rank = 1;
		for (int j = 0; j < num; j++)
		{
			if (x[j] > x[i] && y[j] > y[i])
				rank++;
		}
		rank_num[i] = rank;
	}

	for (int i = 0; i < num; i++)
		printf("%d ", rank_num[i]);
	return 0;
}