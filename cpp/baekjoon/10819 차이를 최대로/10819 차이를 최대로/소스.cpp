#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, arr[8];
	int temp;
	int ans = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	while (next_permutation(arr, arr + N)) {
		temp = 0;
		for (int i = 0; i < N-1; i++) {
			temp += abs(arr[i] - arr[i + 1]);
		}
		ans = max(ans, temp);
	}

	cout << ans;

	return 0;
}