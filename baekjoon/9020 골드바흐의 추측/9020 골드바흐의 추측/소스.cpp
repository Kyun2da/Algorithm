#include <stdio.h>
#include <math.h>
int main()
{
	int arr[10001] = { 0,1 };
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i; j*i<=10000; j ++)
		{
			arr[i * j] = 1;
		}
	}
	/// ��������� �Ҽ����ϱ�, �����佺�׳׽��� ü

	int num;//�׽�Ʈ���̽���
	int a;
	scanf("%d", &num);
	while (num--)
	{
		int min = 10000;
		int b=0, c=0;
		scanf("%d", &a);
		int j = a / 2;
		for (int i = a / 2; i <= a; i++, j--)  //���� ������ �ɰ��� �����ڴ� -- �����ڴ� ++ �ؼ� ã�´ٴ� ������ �߿�
		{ //���� ó�� ã�� ���ڰ� �ڿ������� �μ��� ���� �ּҰ� ��
			if (!arr[i] && !arr[j]) {
				printf("%d %d\n", j, i);
				break;
			}
		}
		
	}
	return 0;
}