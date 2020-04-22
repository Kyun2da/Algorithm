#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool vis[8];
int ans[8];

void dfs(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		bool used[10001]{ false }; //이게 key point 인듯 dfs를 시작할때  모든게 초기화되는거
		for (int i = 0; i < N; i++) {
			if (used[arr[i]] || vis[i]) continue;
			used[arr[i]] = true;
			ans[num] = arr[i];
			vis[i] = true;
			dfs(num + 1);
			vis[i] = false;
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
	dfs(0);
	return 0;
}