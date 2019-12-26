#include <stdio.h>
int main()
{
	int n;
	int hap = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		hap = hap + i;
	}
	printf("%d\n", hap);
	return 0;
}