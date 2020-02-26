#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int dp[50001] = { 0 };
	int arr[224] = { 0 };
	int num;
	int ans = 1;
	int minnum = 5;
	cin >> num;

	for (int i = 1; i <= 223; i++) { // �������� arr�� ������ ���´�.
		arr[i] = i * i;
	}

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= num; i++) {
		minnum = 4; //�ִ� 4�������̹Ƿ� �ʱ�ȭ�� 4�� �Ѵ�
		
		for (int j = 1; arr[j] <= i; j++) { //�������� �����ͺ��� �����鼭 ���� �۾Ҵ� ���� ���ϰ� �ű⿡ +1�� �ϸ� �ȴ�.
			int tmp = i - arr[j]; 
			minnum = min(minnum, dp[tmp]);
		}

		dp[i] = minnum + 1;
	}

	cout << dp[num];
	return 0;
}