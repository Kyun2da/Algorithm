#include <iostream>
#include <memory.h>
using namespace std;

int arr[50][50]; //배추밭
int vis[50][50]; //방문여부
int num = 0; //지렁이수
int T, M, N, K, row, col; // M: 가로길이, N : 세로길이
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //상, 하, 좌, 우

bool isInside(int y, int x) {
	return (y >= 0 && x >= 0 && y < N && x < M);
}

void dfs(int y, int x) {
	vis[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nxt_y = y + direction[i][0];
		int nxt_x = x + direction[i][1];

		if (isInside(nxt_y, nxt_x) && vis[nxt_y][nxt_x] == 0 && arr[nxt_y][nxt_x] == 1) {
			dfs(nxt_y, nxt_x);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	
	cin >> T;

	while (T--) {
		num = 0;
		fill_n(&arr[0][0], 50 * 50, 0);
		fill_n(&vis[0][0], 50 * 50, 0);
		cin >> M >> N >> K;
		
		for (int i = 0; i < K; i++) {
			cin >> col >> row;
			arr[row][col] = 1; //문제가 배추의 가로길이 세로길이 먼저나오므로 말에 맞지않게 두개의 위치를 바꿈
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && vis[i][j] == 0) {
					dfs(i, j);
					num++;
				}
			}
		}
		cout << num << "\n";
	}
	return 0;
}