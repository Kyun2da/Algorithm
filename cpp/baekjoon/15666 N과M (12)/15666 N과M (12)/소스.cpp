#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[8];
int ans[8];
void dfs(int num, int max_num) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		bool chk[10001]{ false };
		for (int i = 0; i < N; i++) {
			if (chk[arr[i]] || max_num > arr[i])continue;
			max_num = arr[i];
			chk[arr[i]] = true;
			ans[num] = arr[i];
			dfs(num + 1, max_num);
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
	dfs(0, -1);
	return 0;
}