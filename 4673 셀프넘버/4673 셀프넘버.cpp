#include <stdio.h>

int a[10001] = { 0 };
void d()
{
	for (int i = 1; i <= 10000; i++)
	{
		int b = i / 10000;     //���� �ڸ���
		int c = i / 1000 % 10; //õ�� �ڸ���
		int d = i / 100 % 10; //���� �ڸ���
		int e = i / 10 % 10; //���� �ڸ���
		int f = i % 10; //���� �ڸ���
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