#include <stdio.h>

int main()
{
	char B[8][8]; //맨 첫칸이 B일 때
	char W[8][8]; //맨 첫칸이 W일 때
	char prob[50][50];
	int a, b;
	//초기화
	for(int i=0; i<8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				B[i][j] = 'B';
				W[i][j] = 'W';
			}
			else
			{
				B[i][j] = 'W';
				W[i][j] = 'B';
			}
		}
	
	//입력
	scanf("%d %d", &a, &b);
	getchar();
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%c", &prob[i][j]);
		}
		getchar();
	}
	
	/*for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%c", prob[i][j]);
		}
		printf("\n");
	}*/
	int error1 = 0, error2=0;
	int min = 2500;
	for (int i = 0; i <= a - 8; i++)
	{
		for (int j = 0; j <= b - 8; j++)
		{
			error1 = 0;
			error2 = 0;
			for (int k = i; k < 8 + i; k++)
			{
				for (int m = j; m < 8 + j; m++)
				{
					if (W[k - i][m - j] != prob[k][m])
						error1++;
					if (B[k - i][m - j] != prob[k][m])
						error2++;
				}
			}
			if (min > error1)
				min = error1;
			if (min > error2)
				min = error2;
		}
	}
	printf("%d", min);
	return 0;
}