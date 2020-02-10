#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool vis[10];

void dfs(int length, int max_num) {
	if (length == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (max_num <= i) {
			arr[length + 1] = i;
			vis[length + 1] = true;
			dfs(length + 1, i);
			vis[length + 1] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[1] = i;
		vis[i] = true;
		dfs(1, i);
		vis[i] = false;
	}
	return 0;
}