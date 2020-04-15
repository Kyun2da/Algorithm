//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	cin.tie(0);
//	ios::sync_with_stdio(0);
//	int arr[10];
//	for (int i = 1; i <= 9; i++) {
//		arr[i] = pow(10, i - 1) * 9 * i;
//	}
//
//	int N, temp, jari = 0, sum = 0;
//	cin >> N;
//	temp = N;
//	while (temp != 0) {
//		temp /= 10;
//		jari++;
//	}
//	for (int i = 1; i < jari; i++) {
//		sum += arr[i];
//	}
//	sum += (N - (pow(10, jari - 1) - 1)) * jari;
//	cout << sum << "\n";
//	return 0;
//}

//자리수로 생각
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int ans = 0, i = 1;
	while (i <= n) {
		ans += (n - i + 1);
		i *= 10;
	}
	cout << ans << "\n";
	return 0;
}