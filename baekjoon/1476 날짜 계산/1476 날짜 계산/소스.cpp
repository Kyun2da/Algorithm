#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int E, S, M;
	int ans = 1;
	int temp[3] = { 15,28,19 };
	cin >> E >> S >> M;
	while (true) {

		int arr[3] = { ans % temp[0],ans % temp[1],ans % temp[2] };
		for (int i = 0; i < 3; i++) {
			if (arr[i] == 0) {
				arr[i] = temp[i];
			}
		}
		if (arr[0] == E && arr[1] == S && arr[2] == M)
			break;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}