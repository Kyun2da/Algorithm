#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	int arr[10][10];
	int per[10];
	int ans = 10000000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		per[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	while (next_permutation(per, per + N)) {
		int temp = 0;
		bool stop = false;
		for (int i = 0; i < N - 1; i++) {
			if (arr[per[i]][per[i + 1]] == 0) {
				stop = true;
				break;
			}
			temp += arr[per[i]][per[i + 1]];
		}
		if (arr[per[N - 1]][per[0]] == 0 || stop)
			continue;
		temp += arr[per[N - 1]][per[0]];
		ans = min(ans, temp);
	}
	cout << ans;
	return 0;
}