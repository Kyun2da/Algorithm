#include <stdio.h>
#define M_PI 3.14159265358979323846
int main()
{

	double num;
	scanf("%lf", &num);

	printf("%.6f\n", M_PI * num * num);
	printf("%.6f\n", 2*num*num);
	return 0;
}