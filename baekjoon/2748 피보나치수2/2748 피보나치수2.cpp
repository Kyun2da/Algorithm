#include <stdio.h>

int main()
{
	long long arr[91];
	arr[0] = 0, arr[1] = 1;
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld", arr[num]);
	return 0;
}