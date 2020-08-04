//top-down���
//�����ָ� �Ǹ������� �Ծ��ٰ� �����غ�������, ������������ �Դ°��� �����ʴ°��� �ٽ� �ΰ����� ������ �ִ�
//������ ������ ������ ������ �������� �������Ƿ� dp[n-3]+arr[n-1]+arr[n] �� �ϳ��� ����̵ȴ�.
//������ ������ ���������� dp[n-2] + arr[n] �� �Ǵٸ� ����� �ȴ�.
//���������� �����ʴ� dp[n-1]�� �ٸ� ������� �� 3���� ����� ���� ū ��츦 ���� �ȴ�
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int arr[10001], dp[10001];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], max(arr[1] + arr[2], arr[2]+arr[3]));
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 1],max( arr[i] + arr[i - 1] + dp[i - 3], dp[i - 2] + arr[i]));
	}

	cout << dp[n] << endl;


	return 0;
}