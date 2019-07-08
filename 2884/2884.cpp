#include <stdio.h>

int main()
{
	int hour, minute;
	scanf("%d %d", &hour, &minute);
	if (minute >= 45)
		minute = minute - 45;
	else
	{
		if (hour != 0)
			hour = hour - 1;
		else
			hour = 23;
		minute = minute + 15;
	}
	printf("%d %d\n", hour, minute);
	return 0;
}