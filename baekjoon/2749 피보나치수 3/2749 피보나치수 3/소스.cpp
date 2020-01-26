//피사노 주기
// M = 10k 일 때, k > 2 라면, 주기는 항상 15 × 10^(k-1) 입니다.
#include <iostream>
using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;

int fibo[p] = { 0,1 };

int main() {
	long long n;
	cin >> n;
	for (int i = 2; i < p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}
	cout << fibo[n % p] << '\n';
	return 0;
}