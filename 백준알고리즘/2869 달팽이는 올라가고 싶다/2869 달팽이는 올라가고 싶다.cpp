#include <stdio.h>

int main()
{
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	int dab = 0;
	int i = 0;
	i = (V - A) / (A-B);
	dab = i*(A - B);
	while (V > dab)
	{
		i++;
		dab += A;
		if (dab >= V)
			break;
		else
			dab -= B;
		
	}
	printf("%d", i);
	return 0;
}