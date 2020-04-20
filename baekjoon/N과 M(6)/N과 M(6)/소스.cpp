#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool vis[8];
int ans[8];

void dfs(int num, int idx) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = idx + 1; i < N; i++) {
			if (!vis[i]) {
				vis[i] = true;
				ans[num] = arr[i];
				dfs(num + 1, i);
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
		ans[0] = arr[i];
		vis[0] = true;
		dfs(1, i);
		vis[0] = false;
	}
	return 0;
}