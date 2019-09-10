#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N, M; //N:카드의 개수, M:가까워야할값
	scanf("%d %d ", &N, &M);
	int *arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int dab = 0;
	for (int i = 0; i < N-2; i++)
	for (int j=i+1; j<N-1; j++)
	for (int k =j+1; k<N; k++)
	{
		if (arr[i] + arr[j] + arr[k] <= M && M - (arr[i] + arr[j] + arr[k]) < M-dab)
			dab = arr[i] + arr[j] + arr[k];
	}
	printf("%d", dab);
	return 0;
}