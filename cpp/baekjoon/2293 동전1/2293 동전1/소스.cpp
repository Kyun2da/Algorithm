//��������
// C(i) : i��° ������ ��ġ
// D(i, k) : i��° ���α��� ����Ͽ� k�� ���� �� �ִ� ����� ��
// ��ȭ�� :
// if( C(i) > k) : D(i-1,k)  -> i��° ������ ��ġ�� k���� ũ�� D(i,k) = D(i-1,k)
// else if ( C(i) <= k) : D(i, k - C(i)) + D(i-1, k) -> i��° ������ ��ġ�� k���� ������ D(i, k) = i��° ���α��� ����Ͽ� k-C(i)�� ����
// ���ִ� ����� �� + i-1��° ���α��� ����Ͽ� k�� ���� �� �ִ� ����� ��
/*
#include <iostream>

using namespace std;

int n, k, arr[101];
long long int dp[101][10001] = { 0 }; // 4,080,408Bytes = �� 3.9MB+ @ ���Ǿ� �޸��ʰ��� ����Ŵ

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0][0] = 1; //ó�� 0���� �������� 0�� ���� �� �ִ°���� ���� 1�����ش�
	
	for (int i = 1; i <= n; i++) {  //{1,2,5}������մٰ� ����
		for (int j = 0; j <= k; j++) {
			if (arr[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i][j - arr[i]] + dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
*/

//���� ��� ���  n-1�� n�� ������ ����� �������  
#include <iostream>

using namespace std;

int n, k, arr[101];

long long int dp[10001] = { 0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1; //ó�� 0���� �������� 0�� ���� �� �ִ°���� ���� 1�����ش�

	for (int i = 1; i <= n; i++) {  //{1,2,5}������մٰ� ����
		for (int j = 0; j <= k; j++) {
			if (arr[i] <= j) 
				dp[j] += dp[j - arr[i]] ;
		}
	}

	cout << dp[k];
	return 0;
}