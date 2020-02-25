#include <iostream>
#include <cmath>
#define mod 1234567891
#define r 31
using namespace std;
long long int sum = 0;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	string s;
	long long pow_num[51];
	cin >> N >> s;

	pow_num[0] = 1;
	for (int i = 1; i <= 50; i++) {
		pow_num[i] = (pow_num[i - 1] * 31) % mod;
	}
	for (int i = 0; i < N; i++) {
		long long int alpha_num = (s[i] - 'a' + 1) * pow_num[i];
		sum = (sum + alpha_num) % mod;
	}
	cout << sum % mod;

	return 0;
}