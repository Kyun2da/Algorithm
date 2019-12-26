#include <stdio.h>
int arr[1000001] = { 0,1 }; //소수이면 0 소수가아니면 1, 1은소수가아니므로 1
//에라토스테네체의 사용
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

//koosaga 님 코드
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