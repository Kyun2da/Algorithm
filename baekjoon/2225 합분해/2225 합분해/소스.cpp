#include <iostream>

using namespace std;

long long int arr[201][201] = { 0 };
#define mod 1000000000;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	arr[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				arr[j][i] += arr[j - l][i - 1];
				arr[j][i] %= mod;
			}
		}
	}

	cout << arr[N][K] % mod;

	return 0;
}