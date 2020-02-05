#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[1001][1001] = { 0, }; //�丶��
int M, N;

bool isInside(int a, int b) {
	return (a >= 1 && b >= 1 && a <= N && b <= M);
}

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int day = 0;
	queue<pair<int, int>> q;

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j }); // ť�� ����ִ´�.
			}
		}
	}

	if (q.empty()) {  //ó������ ��� �丶�䰡 �;��ִ� ����
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt_x = cur.first + dir[i][0];
			int nxt_y = cur.second + dir[i][1];

			if (isInside(nxt_x, nxt_y)&& arr[nxt_x][nxt_y]==0) { //���� �� ĭ�� �迭 �ȿ��ְ� �丶�䰡 ������ ������������(arr==0)
				arr[nxt_x][nxt_y] = arr[cur.first][cur.second]+1;
				q.push({ nxt_x,nxt_y });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	int max_num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (max_num < arr[i][j])
				max_num = arr[i][j];
		}
	}
	cout << max_num-1;
	
	return 0;
}