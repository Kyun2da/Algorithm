#include <stdio.h>

int main()
{
	int num, H, W, N;
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d %d", &H, &W, &N);
		int custom_num = 0;
		for (int i = 1; i <= W; i++)
		{
			for (int j = 1; j <= H; j++)
			{
				custom_num++;
				if (custom_num == N)
				{
					printf("%d%02d\n", j, i);
				}
			}
		}
	}
	// 이중포문을 printf("%d%02d\n",c%a + a * (c%a == 0) ,(c-1)/a+1);이렇게 간단하게 표현가능
	//출처 : koosaga

}