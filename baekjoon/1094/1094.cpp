#include <stdio.h>

int main()
{
	int Jimin;
	int answer = 0;
	int makdae = 64;
	scanf("%d", &Jimin);
	if (Jimin == 64)
	{
		answer = 1;
	}
	else
	{
		while(Jimin!=0)
		{
			makdae = makdae / 2;
			if (makdae <= Jimin)
			{
				answer = answer + 1;
				Jimin = Jimin - makdae;
			}
		}
	}
	printf("%d", answer);
	return 0;
}