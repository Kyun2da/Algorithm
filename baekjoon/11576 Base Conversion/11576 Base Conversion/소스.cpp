#include <iostream>
#include <cmath>
using namespace std;
void binary(int N, int B) {
	if (N == 0)
		return;
	else {
		binary(N / B, B);
		cout << N % B << " ";
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int A, B;
	int m;
	int arr[25];
	int sum = 0;
	int temp = 1;
	cin >> A >> B;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = m - 1; i >= 0; i--) {
		sum += pow(A, m - i - 1) * arr[i];
	}
	binary(sum, B);
	return 0;
}