#include <stdio.h>

int main()
{
	int ax, ay, bx, by, cx, cy,dx,dy;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
	if (ax == bx)
		printf("%d ", cx);
	else if (ax == cx)
		printf("%d ", bx);
	else
		printf("%d ", ax);
	if (ay == by)
		printf("%d ", cy);
	else if (ay == cy)
		printf("%d ", by);
	else
		printf("%d ", ay);
	return 0;
}