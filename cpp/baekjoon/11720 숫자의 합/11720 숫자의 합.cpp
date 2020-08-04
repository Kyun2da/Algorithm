#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num;
	int sum = 0;
	scanf("%d", &num);
	char *s = (char*)malloc(sizeof(char)*(num+1));
	scanf("%s", s);

	for (int i = 0; i <num ; i++)
	{
		sum += s[i] - '0';
	}
	printf("%d", sum);
	free(s);
	return 0;
}