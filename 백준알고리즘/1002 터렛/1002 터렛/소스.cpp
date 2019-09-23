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
			if (r1 == r2) //������ ���� ���������� ������ ������
				printf("-1\n");
			else //������ ������ �������� �ٸ��� �ѿ��� �ٸ��ѿ��� �ѷ��ΰ�����
				printf("0\n");
		}
		else { //������ �ٸ�
			if ((r1 + r2) > distance && abs(r1 - r2) < distance) //�������� ���� �Ÿ��������� ũ�ų� �Ÿ��� �պ��� ������
				printf("2\n");
			else if ((r1 + r2) == distance || abs(r1 - r2) == distance) //���� �����ϰų� �����ϴ� ���
				printf("1\n");
			else //���� �ѿ��� �ѷ��ΰ� �ְų� �������� �պ��� ���������� �Ÿ��� Ŭ��
				printf("0\n");
		}
	}
	return 0;
}
