#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int arr[25][25]; //지도
int vis[25][25] = { 0, }; //방문 여부
int num = 0; //단지에서 집의 개수를 세는 변수
int N;
int danji_num = 0;
bool isInside(int a, int b) {
	return (a >= 0 && b >= 0 && a < N && b < N);
}
int direction[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };
void dfs(int cur_y, int cur_x) {
	vis[cur_y][cur_x] = 1;
	num++;
	for (int i = 0; i < 4; i++) {
		int y = cur_y+direction[i][0];
		int x = cur_x+direction[i][1];

		if (isInside(y, x) && arr[y][x] == 1 && vis[y][x] == 0)
			dfs(y, x);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector <int> danji; //단지의 집의수를 벡터로 표현
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j]-'0';
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && vis[i][j] == 0) {
				dfs(i, j);
				danji.push_back(num);
				num = 0;
				danji_num++;
			}
		}
	}

	sort(danji.begin(), danji.end());
	cout << danji_num << "\n";
	for (int i = 0; i < danji.size(); i++)
		cout << danji[i] << "\n";
	return 0;
}