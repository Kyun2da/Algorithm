#include <stdio.h>

int main()
{
	int num, sosu,flag=1, sosu_num=0;
	scanf("%d",&num);

	for (int i = 0; i < num; i++)
	{
		flag = 1;
		scanf("%d", &sosu);
		if (sosu == 1)
			flag = 0;
		else if (sosu == 2)
			flag = 1;
		else if (sosu % 2 == 0)
			flag = 0;
		else 
		{
			for (int j = sosu-1; j >= 3; j--)
			{
				if (sosu % j == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
			sosu_num += 1;
	}
	printf("%d", sosu_num);

	return 0;
}