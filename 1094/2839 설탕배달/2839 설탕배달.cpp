#include <stdio.h>

int main()
{
		int num; //�Է¹��� ����
		int dab = 0; //��
		int fivemok = 0; //5�� ������ �ϳ��� �����鼭 5�� ������ִ� ����� ���� ã�� 
		                 //������ ������ 5�� ������������ �ָӴ��� ������ �������̱� ����
		scanf("%d", &num);
		if (num >= 5)
			fivemok = num / 5;
		while (fivemok > 0)
		{
			if ((num - (fivemok * 5)) % 3 == 0)
			{
				dab = fivemok + ((num - (fivemok * 5)) / 3);
				break;
			}
			fivemok--;
		}
		if (dab == 0 && num % 3 == 0) //5�� ����� ���������Ƿ� ���������� 3���θ� �������°�찡 �ִ��� Ž��
			dab = num / 3;
		else if (dab == 0) // ���� ��츦 ���غ������� ���� 0�̸� ���̾��°���
			dab = -1;
		printf("%d\n", dab);
	return 0;
}