#include <iostream>

using namespace std;

int main()
{
	long long fibo0[41], fibo1[41];
	int n,num;

	fibo0[0] = 1, fibo0[1] = 0;
	fibo1[0] = 0, fibo1[1] = 1;

	
	for (int i = 2; i <= 40; i++)
	{
		fibo0[i] = fibo0[i - 1] + fibo0[i - 2];
		fibo1[i] = fibo1[i - 1] + fibo1[i - 2];
	}

	cin >> n;
	while (n--)
	{
		cin >> num;
		cout << fibo0[num] << " " << fibo1[num] << endl;
	}

	return 0;
}

//���⼭ fibo0 -> fibo1�� ��ĭ �ڶ�� ���� �� �� �����Ƿ� 
/*
#include<stdio.h>
int a[42] = { 1 }, n, t;
int main() {
	scanf("%d", &t);
	for (int i = 2; i < 42; i++)a[i] = a[i - 1] + a[i - 2];
	for (int i = 0; i < t; i++)scanf("%d", &n), printf("%d %d\n", a[n], a[n + 1]);
}
*/
//�޸� ȿ���� ����ؼ� �̷��� �� �� �ִ�.