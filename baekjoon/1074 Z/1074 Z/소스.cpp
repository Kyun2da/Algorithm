#include <iostream>

using namespace std;
int cnt = 0;
int r, c;
void divide_conquer(int size, int y, int x) {
	if (size == 2) {
        if (y == r && x == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        if (y == r && x + 1 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        if (y + 1 == r && x == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        if (y + 1 == r && x + 1 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        return;
	}
	divide_conquer(size / 2, y, x); //왼쪽위
	divide_conquer(size / 2, y, x + size / 2); //오른쪽위
	divide_conquer(size / 2, y+ size / 2, x); //왼쪽아래
	divide_conquer(size / 2, y + size / 2, x + size / 2); //오른쪽아래
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, ans; //N이 주어졌을 때 (r,c)를 몇번째로 방문하는 지 탐색
	
	cin >> N >> r >> c;

	divide_conquer(1<<N,0,0); // 비트연산자 1<<N은 2의N제곱을 의미한다. 


	return 0;
}