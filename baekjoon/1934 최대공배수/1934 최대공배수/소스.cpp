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

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int num;
	int a, b;

	cin >> num;
	while (num--) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
	return 0;
}