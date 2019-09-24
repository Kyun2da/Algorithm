#include <stdio.h>

int main()
{
		int num;
		int sum = 0;
		int i = 1;
		scanf("%d", &num);
		for (i = 1; i <= num; i++)
		{
			sum = i;
			int j = i;
			while (j != 0)
			{
				sum = sum + (j % 10);
				j = j / 10;
			}
			if (sum == num)
				break;
			//printf("%d : %d\n",i, sum);
		}
		if (i >= num)
			printf("0\n");
		else
			printf("%d\n", i);
		return 0;
	
}