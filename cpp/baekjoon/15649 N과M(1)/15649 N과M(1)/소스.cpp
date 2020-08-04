#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool vis[10];

void dfs(int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++ ) {
		if (vis[i])
			continue;
		vis[i] = true;
		arr[length] = i;
		dfs(length + 1);
		vis[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[0] = i;
		vis[i] = true;
		dfs(1);
		vis[i] = false;
	}
	return 0;
}