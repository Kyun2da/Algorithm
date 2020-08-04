#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int N, M;
int arr[1001][1001];
int vis[1001][1001][2]; //0은 방을 부술수없을때 갔을 때 1은 방을 부술 수 있을때 갔을때
int isInside(int a, int b) {
	return (a >= 1 && b >= 1 && a <= N && b <= M);
}

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	queue <pair<pair<int, int>,int>> q; // y좌표 , x좌표 , 벽뚫횟수

	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //방문했나의 여부를 0으로 초기화하고 벽을 부술 수 있는 횟수를 1로 초기화
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 2; k++) {
				vis[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) { //input 입력
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	q.push(make_pair(make_pair(1, 1), 1));
	vis[1][1][1] = 1;

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxt_y = cur.first.first + dir[i][0]; //다음 y좌표
			int nxt_x = cur.first.second + dir[i][1]; //다음 x좌표
			int nxt_z = cur.second; //현재 벽뚫가능횟수
			if (isInside(nxt_y, nxt_x) && arr[nxt_y][nxt_x]==0 && vis[nxt_y][nxt_x][nxt_z]==0) { 
				//좌표가 안에있고 벽이아닌방이고 방문한적이 없으면 현재벽뚫횟수방으로방문넘겨주고끝
				q.push(make_pair(make_pair(nxt_y, nxt_x), nxt_z));
				vis[nxt_y][nxt_x][nxt_z] = vis[cur.first.first][cur.first.second][cur.second] + 1;
			}
			if (isInside(nxt_y, nxt_x) && arr[nxt_y][nxt_x] == 1 && nxt_z == 1) {
				//좌표가 안에있고 다음갈 방이 벽이며 현재 벽뚫횟수가 1남았다면
				q.push(make_pair(make_pair(nxt_y, nxt_x), nxt_z-1)); //벽뚫가능횟수를 0으로하고 푸시
				vis[nxt_y][nxt_x][nxt_z-1] = vis[cur.first.first][cur.first.second][cur.second] + 1;
			}
		}
	}

	if (vis[N][M][0] == 0 && vis[N][M][1] == 0)
		cout << -1;
	else if (vis[N][M][0] == 0 && vis[N][M][1] != 0)
		cout << vis[N][M][1];
	else if (vis[N][M][0] != 0 && vis[N][M][1] == 0)
		cout << vis[N][M][0];
	else
		cout << min(vis[N][M][0], vis[N][M][1]);
	


	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << vis[i][j][0];
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << vis[i][j][1];
		}
		cout << "\n";
	}*/
	return 0;
}