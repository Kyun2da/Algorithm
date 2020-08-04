#include <stdio.h>

int main()
{
	int num;
	int A, B;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}