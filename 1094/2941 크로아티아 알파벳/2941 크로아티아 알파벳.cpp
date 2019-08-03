#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);
	int num = 0;
	int k = 0;
	while (s[k] != '\0')
	{
		if (s[k] == 'c' && (s[k + 1] == '=' || s[k + 1] == '-'))
			k++;
		else if (s[k] == 'd' && s[k + 1] == 'z' && s[k + 2] == '=')
			k+=2;
		else if (s[k] == 'd' && s[k + 1] == '-')
			k++;
		else if (s[k] == 'l' && s[k + 1] == 'j')
			k++;
		else if (s[k] == 'n' && s[k + 1] == 'j')
			k++;
		else if (s[k] == 's' && s[k + 1] == '=')
			k++;
		else if (s[k] == 'z' && s[k + 1] == '=')
			k++;
		k++;
		num++;
	}
	printf("%d", num);
	return 0;
}