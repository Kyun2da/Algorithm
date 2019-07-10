#include <stdio.h>

int main()
{
	int num;
	int dab = 0;
	int jumsu = 0;
	char s[81] = {'\0'};
	int score[81] = {0};
	int num2 = 0;
	scanf("%d ", &num);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%s", s);
		for(int j=0;j<80; j++)
		{
			if (s[j] == '\0')
				break;
			if (s[j] == 'O')
			{
				jumsu+=1;
				score[j] = jumsu;
			}
			else
			{
				jumsu = 0;
				score[j] = jumsu;
			}
			num2 += 1;
		}
		for (int k = 0; k<num2; k++)
		{
			dab += score[k];
			//printf("%d ", score[k]);
		}
		//printf("\n");
		printf("%d\n", dab);
		jumsu = 0;
		dab = 0;
		num2 = 0;
	}
	return 0;
}