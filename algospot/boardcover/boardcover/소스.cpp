#include <iostream>

using namespace std;


int C, H, W; //C : �׽�Ʈ ���̽��� ��, H : ����, W : ����

//��� ���
const int coverType[4][3][2]{
	{{0,0}, {1,0},{0,1}}, // �� ��
	{{0,0}, {0,1},{1,1}}, // ����
	{{0,0}, {1,0},{1,1}}, // ����
	{{0,0}, {1,0},{1,-1}} // �� ��
};

bool set(int board[][20], int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			ok = false;
		else if ((board[ny][nx] += delta) > 1) //ä������ board[ny][nx]�� 1�̵ɰ��̰� ���°Ÿ� 0�� �ɰ��̴�.
			ok = false;
	}
	return ok;
}

int cover(int board[][20]) {
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) { //����ִ� ���� ������ ĭ�� ������ ĭ�� ã�´�.
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) //�̹� ã�Ҵٸ� �׳� break
			break;
	}
	
	//��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if (y == -1) return 1;
	int ret = 0; //�����
	for (int type = 0; type < 4; type++) { //����� ����� �ϳ��ϳ� �־�� �������� ã�´�.
		//board[y][x]�� type���·� ���� �� ������ ���ȣ���Ѵ�.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//������ ����� ġ���.
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
				 arr[i][j] = (s[j]== '#') ? 1 : 0; //#�� 1�� .�� 0���� �ٲ۴�
			}
		}

		cout << cover(arr) << "\n";
	}
	return 0;
}