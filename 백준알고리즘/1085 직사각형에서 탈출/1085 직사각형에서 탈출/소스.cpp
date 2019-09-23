#include <stdio.h>
int min(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}
int main()
{
	int x, y, w, h,a,b,c,d;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	a = x - 0;
	b = y - 0;
	c = w - x;
	d = h - y;
	int e=min(min(a, b), min(c, d));
	printf("%d\n", e);

	return 0;
}