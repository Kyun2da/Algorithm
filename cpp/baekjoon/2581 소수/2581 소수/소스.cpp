#include <stdio.h>
int arr[1000001] = { 0,1 }; //�Ҽ��̸� 0 �Ҽ����ƴϸ� 1, 1���Ҽ����ƴϹǷ� 1
//�����佺�׳�ü�� ���
int main()
{
	int a,b, min, sum=0;
	scanf("%d %d", &a, &b);
	
	for (int i = 2; i <= b; i++)
	{
		for (int j = 2; i*j <= b; j++)
		{
			arr[j*i] = 1;
		}
	}
	for (int i = b; i >= a; i--)
	{
		if (!arr[i])
		{
			sum += i;
			min = i;
		}
	}
	if (sum > 0)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1\n");
	return 0;
}

//koosaga �� �ڵ�
//#include <cstdio>
//
//int m, n;
//int vis[1000005];
//int main() {
//	scanf("%d %d", &m, &n);
//	for (int i = 2; i <= n; i++) {
//		if (!vis[i]) {
//			if (i >= m) printf("%d\n", i);
//			for (int j = i; j <= n; j += i) {
//				vis[j] = 1;
//			}
//		}
//	}
//}