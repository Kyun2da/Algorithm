#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int ans[8];
bool vis[8];
void dfs(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				ans[num] = arr[i];
				vis[i] = true;
				dfs(num + 1);
				vis[i] = false;
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		vis[i] = true;
		ans[0] = arr[i];
		dfs(1);
		vis[i] = false;
	}
	return 0;
}