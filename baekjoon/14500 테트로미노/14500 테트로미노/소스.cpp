#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500];
bool visit[500][500];

int N, M;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

//DFS�� �� �� �ִ� ����� ������
int tetromino(int x, int y, int cnt) {
	if (cnt >= 5) {
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (visit[nx][ny] == false) {
				visit[nx][ny] = true;
				ans = max(ans, tetromino(nx, ny, cnt + 1) + arr[x][y]);
				visit[nx][ny] = false;
			}
		}
	}
	return ans;
}
//�Ǹ���� DFS�� ����� �� �����Ƿ� ���� �����ش�.
int exShape(int x, int y) {
	int ans = 0;
	// �Ǹ��
	if (x >= 1 && y >= 1 && y < M - 1)
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1]);
	// �̸��
	if (x < N - 1 && y >= 1 && y < M - 1)
		ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1]);
	// �����
	if (x < N - 1 && x >= 1 && y < M - 1)
		ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y + 1]);
	// �ø��
	if (x < N - 1 && x >= 1 && y >= 1)
		ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y - 1]);
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			ans = max(ans, exShape(i, j));
			ans = max(ans, tetromino(i, j, 1));
			visit[i][j] = false;
		}
	}

	printf("%d\n", ans);
	return 0;
}