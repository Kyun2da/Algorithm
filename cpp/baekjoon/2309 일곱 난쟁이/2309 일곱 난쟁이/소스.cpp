#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int arr[9], sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			int temp = sum - arr[i] - arr[j];
			if (temp == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << arr[k]<<"\n";
					}
				}
				return 0;
			}
		}
	}


	return 0;
}