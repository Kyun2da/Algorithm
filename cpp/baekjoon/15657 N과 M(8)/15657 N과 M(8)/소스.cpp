#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int ans[8];
void dfs(int num, int max) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (max <= arr[i]) {
				ans[num] = arr[i];
				if (ans[num] > max)
					max = ans[num];
				dfs(num + 1, max);
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
		dfs(1, ans[0]);
	}
	return 0;
}