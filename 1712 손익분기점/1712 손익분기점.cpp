#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int i = 0;
	if (B >= C)
	{
		printf("-1");
		return 0;
	}
	while (A + (B*i) >= C*i)
	{
		i++;
	}
	printf("%d", i);

	return 0;
}