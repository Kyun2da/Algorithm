//동전문제
// C(i) : i번째 코인의 가치
// D(i, k) : i번째 코인까지 사용하여 k를 만들 수 있는 경우의 수
// 점화식 :
// if( C(i) > k) : D(i-1,k)  -> i번째 코인의 가치가 k보다 크면 D(i,k) = D(i-1,k)
// else if ( C(i) <= k) : D(i, k - C(i)) + D(i-1, k) -> i번째 코인의 가치가 k보다 작으면 D(i, k) = i번째 코인까지 사용하여 k-C(i)를 만들
// 수있는 경우의 수 + i-1번째 코인까지 사용하여 k를 만들 수 있는 경우의 수
/*
#include <iostream>

using namespace std;

int n, k, arr[101];
long long int dp[101][10001] = { 0 }; // 4,080,408Bytes = 약 3.9MB+ @ 가되어 메모리초과를 일으킴

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0][0] = 1; //처음 0개의 코인으로 0을 만들 수 있는경우의 수는 1로해준다
	
	for (int i = 1; i <= n; i++) {  //{1,2,5}가들어잇다고 가정
		for (int j = 0; j <= k; j++) {
			if (arr[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i][j - arr[i]] + dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
*/

//위의 방법 대신  n-1에 n을 덮어씌우는 방식을 사용하자  
#include <iostream>

using namespace std;

int n, k, arr[101];

long long int dp[10001] = { 0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1; //처음 0개의 코인으로 0을 만들 수 있는경우의 수는 1로해준다

	for (int i = 1; i <= n; i++) {  //{1,2,5}가들어잇다고 가정
		for (int j = 0; j <= k; j++) {
			if (arr[i] <= j) 
				dp[j] += dp[j - arr[i]] ;
		}
	}

	cout << dp[k];
	return 0;
}