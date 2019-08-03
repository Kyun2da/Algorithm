#include <stdio.h>

int main()
{
	char s[16];
	scanf("%s", s);
	int num = 0;
	int k = 0;
	while (s[k] != '\0')
	{
		if(s[k]>=65 && s[k]<=67)
			num += 3;
		else if(s[k] >= 68 && s[k] <= 70)
			num += 4;
		else if (s[k] >= 71 && s[k] <= 73)
			num += 5;
		else if (s[k] >= 74 && s[k] <= 76)
			num += 6;
		else if (s[k] >= 77 && s[k] <= 79)
			num += 7;
		else if (s[k] >= 80 && s[k] <= 83)
			num += 8;
		else if (s[k] >= 84 && s[k] <= 86)
			num += 9;
		else if (s[k] >= 87 && s[k] <= 90)
			num += 10;
		k++;
	}
	printf("%d", num);
	return 0;
}