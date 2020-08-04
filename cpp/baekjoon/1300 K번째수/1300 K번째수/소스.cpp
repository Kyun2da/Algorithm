#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K; // N*N ���, K��° ���� ���ؾ���

	int left = 1, right = K, ans;
	while (left <= right) {
		long long cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) cnt += min(mid / i, N); //mid���� �������� ����
		if (cnt < K) left = mid + 1;
		else ans = mid, right = mid - 1;
	}
	cout << ans;

	return 0;
}