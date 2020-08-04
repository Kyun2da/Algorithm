#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	int arr[8];
	cin >> N;
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << "\n";
	while (next_permutation(arr, arr + N)) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}