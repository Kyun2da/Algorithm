#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int N;
int time[15];
int val[15];

void dfs(int day, int value) {
	if (day > N) return;
	if (day == N) {
		if (value > ans) ans = value;
		return;
	}

	dfs(day + time[day], value + val[day]); //����� �ϱ���Ѱ��
	dfs(day + 1, value); //��������ϰ� �������� �Ѿ�� ���
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time[i] >> val[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}