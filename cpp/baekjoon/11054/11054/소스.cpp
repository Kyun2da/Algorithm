//�� �迭���� arr�� �ε����� �� �κ� ������ ���Ѵ�
//1 5 2 1 4 3 4 5 2 1 - �迭 ����
//1 2 2 1 3 3 4 5 2 1 - ���ʺ��� ������������ �κм��� ����
//1 5 2 1 4 3 3 3 2 1 - �����ʺ��� ���������� �κм��� ����
//1 6 3 1 6 5 6 7 3 1 - ���� �ΰ����� 1�� ���� ������ ���� ���� �� ������� ������ ���̸� ã�� �� �ִ�.

#include <iostream>

using namespace std;

int main() {
	int N;
	int a[1001];
	int dp[1001];
	int dp2[1001];
	int dp_max2 = 0;
	int dp_max = 0;
	int answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	//���ʺ��� �������� �κм��� ���̸� ã�� ��
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp_max = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dp_max < dp[j]) { //���ϰ����ϴ� �迭���� ũ�� �� ���� dp�����ٴ� Ŀ���Ѵٴ� ��
				dp_max = dp[j];
			}
		}
		dp[i] = dp_max + 1;
	}

	dp2[N] = 1;
	for (int i = N-1; i >= 1; i--) {
		dp_max2 = 0;
		for (int j = N; j > i; j--) {
			if (a[j] < a[i] && dp_max2 < dp2[j]) {
				dp_max2 = dp2[j];
			}
		}
		dp2[i] = dp_max2 + 1;
	}

	for (int i = 1; i <= N; i++) {
		if (answer < dp[i] + dp2[i]-1) //dp �ΰ��� ���� 1�� ������ ���� �ȴ�.
			answer = dp[i]+dp2[i]-1;
	}

	cout << answer;
	return 0;
}