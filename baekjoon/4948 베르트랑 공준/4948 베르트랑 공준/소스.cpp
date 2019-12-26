#include <stdio.h>

//에라토스테네스의 체사용

int main()
{
	int arr[246913] = { 0,1 }; //1은소수가 아니므로 1로
	for (int i = 2; i <= 246912; i++)
	{
		for (int j = 2; i * j <= 246912; j++)
		{
			arr[j * i] = 1;
		}
	}
	while (1)
	{
		int num;
		int sosu_num=0;
		scanf("%d", &num);
		if (num == 0)
			return 0;
		

		for (int i = num+1; i <= 2 * num; i++)
		{
			if (!arr[i])
				sosu_num += 1;
		}
		printf("%d\n", sosu_num);
	}

	return 0;
}