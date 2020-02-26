#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int dp[50001] = { 0 };
	int arr[224] = { 0 };
	int num;
	int ans = 1;
	int minnum = 5;
	cin >> num;

	for (int i = 1; i <= 223; i++) { // 제곱수를 arr에 저장해 놓는다.
		arr[i] = i * i;
	}

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= num; i++) {
		minnum = 4; //최대 4개까지이므로 초기화를 4로 한다
		
		for (int j = 1; arr[j] <= i; j++) { //제곱수를 작은것부터 빼보면서 가장 작았던 수를 구하고 거기에 +1을 하면 된다.
			int tmp = i - arr[j]; 
			minnum = min(minnum, dp[tmp]);
		}

		dp[i] = minnum + 1;
	}

	cout << dp[num];
	return 0;
}