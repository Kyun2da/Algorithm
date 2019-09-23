#include <stdio.h>
#include <math.h>
int main()
{
	int x1, y1, r1, x2, y2, r2;
	int num;
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) //중점이 같고 반지름또한 같으면 같은원
				printf("-1\n");
			else //중점은 같은데 반지름이 다르면 한원이 다른한원을 둘러싸고있음
				printf("0\n");
		}
		else { //중점이 다름
			if ((r1 + r2) > distance && abs(r1 - r2) < distance) //반지름의 합이 거리의차보다 크거나 거리의 합보다 작을때
				printf("2\n");
			else if ((r1 + r2) == distance || abs(r1 - r2) == distance) //원이 내접하거나 외접하는 경우
				printf("1\n");
			else //원이 한원을 둘러싸고 있거나 반지름의 합보다 중점사이의 거리가 클때
				printf("0\n");
		}
	}
	return 0;
}
