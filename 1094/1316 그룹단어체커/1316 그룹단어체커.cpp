#include <stdio.h>

int main()
{
	
	
	
	int dab = 0;
	int num = 0;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		int alphabetnum; //알파벳을 아스키코드로 변환
		int yeonsok = 0; //연속적이지 않은 알파벳이 있는지의 여부
		char s[101] = {'\0',};
		int a[26] = { 0, };
		scanf("%s", s);
		int k = 0;
		while (s[k] != '\0')
		{ 
			//printf("%d", s[k]);
			a[(int)s[k]-97] += 1;
			
			if ((k != 0) && (a[(int)s[k]-97] >= 2) && (s[k] != s[k - 1])) //a[alphabetnum-97]>=2는 글자가 두개이상 
			{
				yeonsok = 1;
				break;
			}
			k++;
		}
		if (yeonsok == 0)
			dab += 1;
		yeonsok = 0;
		/*printf("%d", dab);*/
	}
	printf("%d", dab);
	return 0;
}