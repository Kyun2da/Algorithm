#include <stdio.h>
#include <math.h>
int main()
{
	int num;
	scanf("%d", &num);
	int n = 0; ///666���ִ� ���� ����
	int a = 666; //666���� ����
	//�������� 666�ΰ��� Ȱ��
	while (n != num)
	{
		int b = a;
		while (b != 0)
		{
			if (b % 1000 == 666)
			{
				n += 1;
				break;
			}
			b = b / 10;
		}
		if (n == num)
		{
			printf("%d\n", a);
			break;
		}
		a++;
	}
	return 0;
}