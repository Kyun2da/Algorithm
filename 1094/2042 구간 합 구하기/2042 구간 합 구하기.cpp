#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N, M, K;
	int a, b, c;
	int sum = 0;
	scanf("%d %d %d", &N, &M, &K);
	int *arr = (int*)malloc(sizeof(int)*N);
	int *hap = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		hap[i] = sum;
	}
	/*for (int j = 0; j < N; j++)
	{
		printf("%d", arr[j]);
	}*/

	for (int j = 0; j < M + K; j++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			arr[b-1] = c;
		}
		else
		{
			printf("%d\n", sum);
			sum = 0;
		}
	}
	return 0;
}