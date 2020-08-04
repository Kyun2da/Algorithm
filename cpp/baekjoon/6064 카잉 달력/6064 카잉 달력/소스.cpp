#include <stdio.h>
//�ִ� �����(gcd)
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		int M, N, x, y, j;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int lcm_num = lcm(M, N);
		for (j = x; j <= lcm_num; j+=M)
		{
			int temp = (j % N == 0) ? N : j % N; 
			//j%N�� 0�̵ɽÿ� N�� Y�� ���� ������ �ذ��Ҽ� �����Ƿ� ���Ͱ��� �ٲ��ش�
			if (temp == y) {
				printf("%d\n", j);
				break;
			}
		}
		if (j > lcm_num)
			printf("-1\n");
	}

	return 0;
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}