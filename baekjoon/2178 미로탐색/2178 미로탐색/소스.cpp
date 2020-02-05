#include <iostream>
#include <queue>

using namespace std;

int N, M; // N*Mũ���� �̷�
int arr[101][101] = { 0, }; //�̷�
int vis[101][101] = { 0, }; //�湮����
int max = 10000; //�ִܰ��
bool isInside(int a, int b) {
	return (a >= 1 && a <= N && b >= 1 && b <= M);
}

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j-1] - '0';
		}
	}

	queue <pair<int, int>> q;
	q.push({ 1,1 });
	vis[1][1] = 1;
	while (!q.empty()) { //bfs�� Ž���ϸ� ��ĭ�� �����Ҷ����� �̷��� ���� +1�� ���ش�
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt_x = cur.first + dir[i][0];
			int nxt_y = cur.second + dir[i][1];
			if (isInside(nxt_x, nxt_y) && arr[nxt_x][nxt_y] != 0 && vis[nxt_x][nxt_y]==0) //�ȿ� ����ְ�, �����մ� ĭ�̸�, �湮������ ���� ĭ
			{
				arr[nxt_x][nxt_y] = arr[cur.first][cur.second] + 1;
				q.push({ nxt_x,nxt_y });
				vis[nxt_x][nxt_y] = 1;
			}
		}
	}

	cout << arr[N][M];
	return 0;
}