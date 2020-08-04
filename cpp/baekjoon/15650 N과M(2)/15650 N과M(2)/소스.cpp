#include <iostream>

using namespace std;

int arr[10];  //숫자의 자리수만큼 배열공간을 차지
bool vis[10]; //숫자 몇번을 방문했는지의 여부
int N, M;  //1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열

void dfs(int length, int max) {
	if (length == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!vis[i] && max < i) {
			arr[length + 1] = i;
			vis[i] = true;
			dfs(length + 1, i);
			vis[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		
		arr[1] = i;
		vis[i] = true;
		dfs(1, i);
		vis[i] = false;
	}
	return 0;
}