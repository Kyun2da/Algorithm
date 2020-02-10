#include <iostream>

using namespace std;

int arr[10];  //������ �ڸ�����ŭ �迭������ ����
bool vis[10]; //���� ����� �湮�ߴ����� ����
int N, M;  //1���� N���� �ڿ��� �߿��� �ߺ����� M���� �� ����

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