#include <stdio.h>
#include <math.h>
int main()
{
	//���������� �����̿��ؼ� ���Ѵ�
	//1, 2~3, 4~6 �̷������� �밢������ �����ϹǷ�
	int firstnum; //�������� �ش� bn�̽����ϴ� ó�� ��
	int bunmo = 0;
	int bunja = 0;
	long long int num;
	scanf("%lld", &num);
	long long int dab = 0.5 + sqrt(0.25 - 2 + 2 * num);
	firstnum = 1 + (dab*(dab - 1)) / 2; //���������� ���Ļ�� 
	//printf("%d\n", dab);

	if (dab == 1)
	{
		bunmo = 1, bunja = 1;
	}
	else
	{
		if (dab % 2 == 0) //¦���� �и� dab���� ����
		{
			bunmo = dab;
			bunja = 1;
			for (int i = firstnum; i < num; i++)
			{
				bunja += 1;
				bunmo -= 1;
			}
		}
		else //Ȧ���� ���ڰ� dab���� ����
		{
			bunmo = 1;
			bunja = dab;
			for (int i = firstnum; i < num; i++)
			{
				bunja -= 1;
				bunmo += 1;
			}
		}
	}
	printf("%d/%d\n", bunja, bunmo);
	return 0;
}