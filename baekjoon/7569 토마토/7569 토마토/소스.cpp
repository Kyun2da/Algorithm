#include <iostream>
#include <queue>

using namespace std;

int M, N, H; // M : 가로 N : 세로 H : 상자의 수
int arr[101][101][101];
int vis[101][101][101];
bool isInside(int z, int y, int x) {
	return (x >= 1 && x <= M && y >= 1 && y <= N && z >= 1 && z <= H);
}

int dir[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };

int main() {
	queue <pair<pair<int, int>,int>> q;
	bool all = true; //모든 토마토가 저장될때 부터 익은상태인지 
	int max_num = 1;
	cin >> M >> N >> H; 
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					vis[i][j][k] = 1;
					q.push(make_pair(make_pair(i, j), k));
				}
				else if (arr[i][j][k] == 0) {
					all = false;
				}
			}
		}
	}

	if (all) { //모든 토마토가 이미 익어있는 상태라면 0을 출력하고 끝낸다.
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nxt_z = cur.first.first + dir[i][0];
			int nxt_y = cur.first.second + dir[i][1];
			int nxt_x = cur.second + dir[i][2];

			if (isInside(nxt_z, nxt_y, nxt_x)&& vis[nxt_z][nxt_y][nxt_x]!=1 && arr[nxt_z][nxt_y][nxt_x]==0) { //안에있고, 방문하지않은 토마토가 있는경우 
				arr[nxt_z][nxt_y][nxt_x] = arr[cur.first.first][cur.first.second][cur.second] + 1;
				vis[nxt_z][nxt_y][nxt_x] = 1;
				q.push(make_pair(make_pair(nxt_z, nxt_y), nxt_x));
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (arr[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				if (arr[i][j][k] > max_num) {
					max_num = arr[i][j][k];
				}
			}
		}
	}

	cout << max_num - 1;
	return 0;
}