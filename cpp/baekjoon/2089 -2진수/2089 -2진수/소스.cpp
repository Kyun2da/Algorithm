#include <iostream>

using namespace std;
void binary(int a) {
	
	if (a == 1) {
		cout << 1;
		return;
	}

	if (a < 0 && a % -2 == -1) {
		a /= -2;
		a += 1;
		binary(a);
		cout << 1;
	}
	else {
		int temp = a % -2;
		a /= -2;
		binary(a);
		cout << temp;
	}
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	binary(N);

	return 0;
}   