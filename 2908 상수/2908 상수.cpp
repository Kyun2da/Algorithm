#include <stdio.h>
#include <math.h>
int main()
{
	char s1[4];
	char s2[4];
	scanf("%s %s", s1, s2);
	int num1 = 0, num2 = 0;
	for (int i = 0; i < 3; i++)
	{
		num1 += (s1[i] - '0')*pow(10,i);
		num2 += (s2[i] - '0')*pow(10,i);
	}
	if (num1 >= num2)
		printf("%d", num1);
	else
		printf("%d", num2);


	return 0;
}