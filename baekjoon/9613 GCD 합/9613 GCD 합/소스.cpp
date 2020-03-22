#include <iostream>

using namespace std;
int gcd(int a, int b) {
	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int arr[100];
	int t,n;
	long long sum;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";

	}


	return 0;
}