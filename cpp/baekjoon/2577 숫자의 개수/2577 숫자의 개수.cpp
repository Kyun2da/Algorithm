#include <stdio.h>

int main()
{
	int a[10] = {0};
	int A, B, C;
	int namugi;
	scanf("%d %d %d", &A, &B, &C);
	int dab = A * B * C;
	while (dab!= 0)
	{
		namugi = dab % 10;
		a[namugi] += 1;
		dab /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	return 0;
}