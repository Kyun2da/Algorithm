#include <stdio.h>

int main()
{
	float person;
	int testcase;
	float jumsu[1000];
	float sum = 0;
	float mean = 0;
	float overperson = 0;
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++)
	{
		scanf("%f", &person);
		for (int j = 0; j < person; j++)
		{
			scanf("%f", &jumsu[j]);
			sum = sum + jumsu[j];
		}
		mean = sum / (float)person;

		for (int k = 0; k < person; k++)
		{
			if (jumsu[k] > mean)
				overperson += 1;
		}
		printf("%.3f%%\n", overperson / person*100);
		sum = 0; mean = 0; overperson = 0;
	}


	return 0;
}