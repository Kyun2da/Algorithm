#include <iostream>
#define mod 1000000000
using namespace std;

//dp���� �����ڸ���
// �ǳ��ڸ��� 0�ΰ�쿣 �׾��ڸ��� 1�ϼ��ۿ�����
// �ǳ��ڸ��� 9�ΰ�쿣 �׾��ڸ��� 8�ϼ��ۿ�����
// ������ ��쿡�� �յ� �ΰ���case�� �����ϴ�.
int main()
{
	int num;
	long long sum = 0;
	cin >> num;

	int dp[101][10] ; //100������ �ڸ����̹Ƿ�

	
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;   //ù° �ڸ����� 1������ ���̹Ƿ� 1�� �ʱ�ȭ
	
	for (int i = 2; i <= num; i++) //��° �ڸ�������(n)�� ���ϴ��� 
	{	
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) dp[i][0] = dp[i - 1][1]; //���ڸ��� 0�̸� ���ڸ��� 1�ۿ� �ɼ� �����Ƿ�
			else if (j == 9) dp[i][9] = dp[i - 1][8]; //���ڸ��� 9�̸� ���ڸ��� 8�ۿ� �ɼ� �����Ƿ�
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	
	for (int i = 1; i <= 9; i++)
		sum += dp[num][i];

	cout << sum %mod;
	return 0;
}