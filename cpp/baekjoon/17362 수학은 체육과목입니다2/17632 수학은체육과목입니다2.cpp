#include <stdio.h>

int main()
{
	int num;
	int dab;
	int pm=1;
	

	dab = 0;
	scanf("%d", &num);
	int namugi = num % 8;
	if (namugi == 1)
		printf("1");
	else if (namugi == 0 || namugi == 2)
		printf("2");
	else if (namugi == 3 || namugi == 7)
		printf("3");
	else if (namugi == 4 || namugi == 6)
		printf("4");
	else
		printf("5");
	return 0; 
}