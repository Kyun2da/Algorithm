#include <iostream>

using namespace std;

void binary(int N, int B) {
	if (N == 0)
		return;
	else {
		if (N % B >= 10) {
			char c = 55 + N % B;
			binary(N / B, B);
			cout << c;
		}
		else {
			binary(N / B, B);
			cout << N % B;
		}
			
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, B;
	cin >> N >> B;
	binary(N, B);
	

	return 0;
}