#include <stdio.h>
#include <math.h>
int main()
{
	int arr[10001] = { 0,1 };
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i; j*i<=10000; j ++)
		{
			arr[i * j] = 1;
		}
	}
	/// 여기까지가 소수구하기, 에라토스테네스의 체

	int num;//테스트케이스수
	int a;
	scanf("%d", &num);
	while (num--)
	{
		int min = 10000;
		int b=0, c=0;
		scanf("%d", &a);
		int j = a / 2;
		for (int i = a / 2; i <= a; i++, j--)  //수를 반으로 쪼개서 한인자는 -- 한인자는 ++ 해서 찾는다는 개념이 중요
		{ //제일 처음 찾은 숫자가 자연스럽게 두수의 차가 최소가 됨
			if (!arr[i] && !arr[j]) {
				printf("%d %d\n", j, i);
				break;
			}
		}
		
	}
	return 0;
}