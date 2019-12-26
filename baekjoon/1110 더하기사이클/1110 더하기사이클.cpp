#include <stdio.h>

int main()
{
	
	int problem;
	int cycle = 0;
	scanf("%d", &problem);
	int dab = problem;
	problem = (problem % 10 * 10) + (problem / 10 + problem % 10) % 10;
	cycle = 1;
	while (dab != problem)
	{
		problem = (problem % 10 * 10) + (problem / 10 + problem % 10) % 10;
		cycle+=1;
	}
	printf("%d", cycle);
	
	return 0;
}