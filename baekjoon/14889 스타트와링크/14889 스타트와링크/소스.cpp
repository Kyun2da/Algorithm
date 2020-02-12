#include <iostream>

using namespace std;

int N;
int arr[21][21];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}


	return 0;
}