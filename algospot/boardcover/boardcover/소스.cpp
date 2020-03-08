#include <iostream>

using namespace std;


int C, H, W; //C : 테스트 케이스의 수, H : 높이, W : 넓이

//블록 모양
const int coverType[4][3][2]{
	{{0,0}, {1,0},{0,1}}, // ┌ 자
	{{0,0}, {0,1},{1,1}}, // ㄱ자
	{{0,0}, {1,0},{1,1}}, // ㄴ자
	{{0,0}, {1,0},{1,-1}} // ┘ 자
};

bool set(int board[][20], int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			ok = false;
		else if ((board[ny][nx] += delta) > 1) //채웠으면 board[ny][nx]는 1이될것이고 비우는거면 0이 될것이다.
			ok = false;
	}
	return ok;
}

int cover(int board[][20]) {
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) { //비어있는 가장 위쪽의 칸을 왼쪽위 칸을 찾는다.
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) //이미 찾았다면 그냥 break
			break;
	}
	
	//모든 칸을 채웠으면 1을 반환한다.
	if (y == -1) return 1;
	int ret = 0; //방법수
	for (int type = 0; type < 4; type++) { //블록의 모양을 하나하나 넣어보며 가짓수를 찾는다.
		//board[y][x]를 type형태로 덮을 수 있으면 재귀호출한다.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//덮었던 블록을 치운다.
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int arr[20][20];
	string s;
	cin >> C;
	while (C--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
				cin >> s;
			for (int j = 0; j < W; j++) {
				 arr[i][j] = (s[j]== '#') ? 1 : 0; //#은 1로 .은 0으로 바꾼다
			}
		}

		cout << cover(arr) << "\n";
	}
	return 0;
}