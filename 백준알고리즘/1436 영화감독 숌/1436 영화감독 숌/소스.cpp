#include <stdio.h>
#include <math.h>
int main()
{
	int num;
	scanf("%d", &num);
	int n = 0; ///666이있는 수의 갯수
	int a = 666; //666부터 시작
	//나머지가 666인것을 활용
	while (n != num)
	{
		int b = a;
		while (b != 0)
		{
			if (b % 1000 == 666)
			{
				n += 1;
				break;
			}
			b = b / 10;
		}
		if (n == num)
		{
			printf("%d\n", a);
			break;
		}
		a++;
	}
	return 0;
}