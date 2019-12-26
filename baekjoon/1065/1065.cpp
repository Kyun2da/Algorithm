#include <stdio.h>

int main()
{
	int N = 0;
	scanf("%d", &N);
	int answer = 0;
	while (N != 0)
	{
		if (N >= 100)
		{
			if (N / 100 - (N % 100)/10 == (N % 100) / 10 - N % 10)
				answer += 1;

		}
		if (N < 100 && N >= 1)
		{
			answer += 1;
		}

		N--;
	}
	printf("%d", answer);
	return 0;
}