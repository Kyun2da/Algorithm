#include <stdio.h>
#include <math.h>
int main()
{
		long long int num;
		scanf("%lld", &num);
		
		//���������� �̿��Ͽ� 3n^2-3n+2=num�̶�� ������ ����
		long long int dab = (3 + sqrt(9 - 12 * (2 - num))) / 6;
		if (num == 1)
		{
			dab = 0;
		}
		printf("%lld\n", dab + 1);
	return 0;
}