#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int N, M;
int arr[1001][1001];
int vis[1001][1001][2]; //0�� ���� �μ��������� ���� �� 1�� ���� �μ� �� ������ ������
int isInside(int a, int b) {
	return (a >= 1 && b >= 1 && a <= N && b <= M);
}

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	queue <pair<pair<int, int>,int>> q; // y��ǥ , x��ǥ , ����Ƚ��

	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //�湮�߳��� ���θ� 0���� �ʱ�ȭ�ϰ� ���� �μ� �� �ִ� Ƚ���� 1�� �ʱ�ȭ
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 2; k++) {
				vis[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) { //input �Է�
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
			int nxt_y = cur.first.first + dir[i][0]; //���� y��ǥ
			int nxt_x = cur.first.second + dir[i][1]; //���� x��ǥ
			int nxt_z = cur.second; //���� ���հ���Ƚ��
			if (isInside(nxt_y, nxt_x) && arr[nxt_y][nxt_x]==0 && vis[nxt_y][nxt_x][nxt_z]==0) { 
				//��ǥ�� �ȿ��ְ� ���̾ƴѹ��̰� �湮������ ������ ���纮��Ƚ�������ι湮�Ѱ��ְ�
				q.push(make_pair(make_pair(nxt_y, nxt_x), nxt_z));
				vis[nxt_y][nxt_x][nxt_z] = vis[cur.first.first][cur.first.second][cur.second] + 1;
			}
			if (isInside(nxt_y, nxt_x) && arr[nxt_y][nxt_x] == 1 && nxt_z == 1) {
				//��ǥ�� �ȿ��ְ� ������ ���� ���̸� ���� ����Ƚ���� 1���Ҵٸ�
				q.push(make_pair(make_pair(nxt_y, nxt_x), nxt_z-1)); //���հ���Ƚ���� 0�����ϰ� Ǫ��
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