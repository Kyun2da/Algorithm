#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int idx[13];
	int arr[13];
	int ans[6];
	int N;
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < 6; i++) {
			idx[i] = 1;
		}
		for (int i = 6; i < N; i++) {
			idx[i] = 0;
		}
		sort(idx, idx + N, greater<int>());
		do {
			int ans_idx = 0;
			for (int i = 0; i < N; i++) {
				if (idx[i]) {
					ans[ans_idx] = arr[i];
					ans_idx++;
				}
			}
			sort(ans, ans + 6);
			for (int i = 0; i < 6; i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(idx, idx + N));
		cout << "\n";
	}
	return 0;
}