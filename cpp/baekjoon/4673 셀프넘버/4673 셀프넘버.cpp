#include <stdio.h>

int a[10001] = { 0 };
void d()
{
	for (int i = 1; i <= 10000; i++)
	{
		int b = i / 10000;     //¸¸ÀÇ ÀÚ¸´¼ö
		int c = i / 1000 % 10; //ÃµÀÇ ÀÚ¸´¼ö
		int d = i / 100 % 10; //¹éÀÇ ÀÚ¸´¼ö
		int e = i / 10 % 10; //½ÊÀÇ ÀÚ¸´¼ö
		int f = i % 10; //ÀÏÀÇ ÀÚ¸´¼ö
		int num = i + b + c + d + e + f;
		if (num <= 10000)
		{
			a[num] = 1;
		}
	}
}
int main()
{
	a[0] = 0;
	d();
	for (int i = 1; i <= 10000; i++)
	{
		if (a[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}