#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num;
	float max = 0;
	float sum = 0;
	scanf("%d", &num);
	float *subject = (float*)malloc(sizeof(float) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &subject[i]);
		if (subject[i] >= max)
			max = subject[i];
	}
	for (int j = 0; j < num; j++)
	{
		subject[j] = (subject[j] / max) * 100;
		sum += subject[j];
	}

	printf("%.2f", (float)sum / (float)num);
	free(subject);
	return 0;
}