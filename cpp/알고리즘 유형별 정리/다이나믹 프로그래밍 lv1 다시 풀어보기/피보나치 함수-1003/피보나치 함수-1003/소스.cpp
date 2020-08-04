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

//여기서 fibo0 -> fibo1이 한칸 뒤라는 것을 알 수 있으므로 
/*
#include<stdio.h>
int a[42] = { 1 }, n, t;
int main() {
	scanf("%d", &t);
	for (int i = 2; i < 42; i++)a[i] = a[i - 1] + a[i - 2];
	for (int i = 0; i < t; i++)scanf("%d", &n), printf("%d %d\n", a[n], a[n + 1]);
}
*/
//메모리 효율을 고려해서 이렇게 쓸 수 있다.