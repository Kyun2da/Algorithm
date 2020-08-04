#include <iostream>
#include <cmath>
using namespace std;

int arr[100000];

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
	
	int N, S, answer;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] = abs(arr[i]-S);
	}

	answer = gcd(arr[0], arr[1]);
	for (int i = 2; i < N; i++) {
		answer = gcd(answer, arr[i]);
	}
	cout << answer << "\n";
	return 0;
}