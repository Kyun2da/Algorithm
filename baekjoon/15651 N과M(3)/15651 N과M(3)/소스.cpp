#include <iostream>

using namespace std;

int N, M; // 1���� N���� �ڿ����߿��� M���� �� ����

int arr[10];

void dfs(int length) {
	if (length == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[length + 1] = i;
		dfs(length + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[1] = i;
		dfs(1);
	}

	return 0;
}