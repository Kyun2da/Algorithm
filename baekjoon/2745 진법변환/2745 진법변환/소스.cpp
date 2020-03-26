#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string N;
	int B,sum=0;
	cin >> N >> B;

	for (int i = N.length() - 1; i >= 0; i--) {
		int temp = pow(B, N.length() - i-1);
		if (N[i] >= '0' && N[i] <= '9') {
			sum += (N[i] - '0') * temp;
		}
		else {
			sum += (N[i] - 55) * temp;
		}
	}

	cout << sum;
	return 0;
}