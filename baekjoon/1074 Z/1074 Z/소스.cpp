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
	divide_conquer(size / 2, y, x); //������
	divide_conquer(size / 2, y, x + size / 2); //��������
	divide_conquer(size / 2, y+ size / 2, x); //���ʾƷ�
	divide_conquer(size / 2, y + size / 2, x + size / 2); //�����ʾƷ�
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, ans; //N�� �־����� �� (r,c)�� ���°�� �湮�ϴ� �� Ž��
	
	cin >> N >> r >> c;

	divide_conquer(1<<N,0,0); // ��Ʈ������ 1<<N�� 2��N������ �ǹ��Ѵ�. 


	return 0;
}