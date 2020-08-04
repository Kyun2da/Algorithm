#include <stdio.h>

int main()
{
	char s[1000010];
	scanf("%[^\n]", s);
	int num = 1;
	int k = 0;
	int Alphabetnum = 0;
	while (s[k] != '\0')
	{
		if (s[k] != '\0' && s[k] != ' ')
			Alphabetnum += 1;
		if (s[k] == ' ' && k!=0 && s[k+1]!='\0')
			num += 1;
		k++;
	}
	if (Alphabetnum == 0)
		num = 0;
	printf("%d", num);
	return 0;
}