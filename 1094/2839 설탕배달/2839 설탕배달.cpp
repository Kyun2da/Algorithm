#include <stdio.h>

int main()
{
		int num; //입력받을 숫자
		int dab = 0; //답
		int fivemok = 0; //5로 나눈몫 하나씩 빼가면서 5로 만들수있는 경우의 수를 찾음 
		                 //빼가는 이유는 5는 많이있을수록 주머니의 개수가 적을것이기 때문
		scanf("%d", &num);
		if (num >= 5)
			fivemok = num / 5;
		while (fivemok > 0)
		{
			if ((num - (fivemok * 5)) % 3 == 0)
			{
				dab = fivemok + ((num - (fivemok * 5)) / 3);
				break;
			}
			fivemok--;
		}
		if (dab == 0 && num % 3 == 0) //5의 경우의 수가없으므로 마지막으로 3으로만 나눠지는경우가 있는지 탐색
			dab = num / 3;
		else if (dab == 0) // 위의 경우를 다해봤을때도 답이 0이면 답이없는것임
			dab = -1;
		printf("%d\n", dab);
	return 0;
}