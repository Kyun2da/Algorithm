#include <stdio.h>
#include <stdlib.h>
long long sum(int *a, int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += a[i];
	}
	return ans;
}
int main()
{
	int *arr;
	int n;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%u", sum(arr, n));

	return 0;
}