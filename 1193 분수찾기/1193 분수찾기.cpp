#include <stdio.h>
#include <math.h>
int main()
{
	//계차수열의 공식이용해서 구한다
	//1, 2~3, 4~6 이런식으로 대각선으로 시작하므로
	int firstnum; //계차수열 해당 bn이시작하는 처음 수
	int bunmo = 0;
	int bunja = 0;
	long long int num;
	scanf("%lld", &num);
	long long int dab = 0.5 + sqrt(0.25 - 2 + 2 * num);
	firstnum = 1 + (dab*(dab - 1)) / 2; //계차수열의 공식사용 
	//printf("%d\n", dab);

	if (dab == 1)
	{
		bunmo = 1, bunja = 1;
	}
	else
	{
		if (dab % 2 == 0) //짝수면 분모가 dab부터 시작
		{
			bunmo = dab;
			bunja = 1;
			for (int i = firstnum; i < num; i++)
			{
				bunja += 1;
				bunmo -= 1;
			}
		}
		else //홀수면 분자가 dab부터 시작
		{
			bunmo = 1;
			bunja = dab;
			for (int i = firstnum; i < num; i++)
			{
				bunja -= 1;
				bunmo += 1;
			}
		}
	}
	printf("%d/%d\n", bunja, bunmo);
	return 0;
}