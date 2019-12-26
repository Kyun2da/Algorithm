#include <iostream>
using namespace std;
int dp[10001];
int arr[10001];

int max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}
int main()
{
	dp[0] = 0;
	arr[0] = 0;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= num; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1], arr[i] + dp[i - 2]); 
		//�����ְ� i-3��°�� �հ� i-1�� i��°�� ��������(i-2��°�� ���ٰ� ����)
		//�����ְ� i-1��°�� ���϶� (i��°�� ���ٰ����)
		//�����ְ� i��°�� i-2��°������ �������� (i-1��°�� ���ٰ� ����)
		//4���� ���������� ù��° ���� ���ݱ����� ���� ���̰� ���� 3���� ������� ������ ����ϸ� ��
	}
	cout << dp[num];
	return 0;
}