#include <iostream>
using namespace std;
int Tile_arr[1001];

int Tile_num(int x);
//i��° Ÿ���� ���� i-1��°���� 1x2¥�� Ÿ�� �Ѱ����̴� ���� i-2��°���� 2x1 Ÿ�� �ΰ� ���̴� ���� 2x2 Ÿ�� �Ѱ��� ���̴� ���
//�� ��ȭ���� An-1+An-2*2
int main()
{
	int num;
	cin >> num;
	cout << Tile_num(num);

	return 0;
}

int Tile_num(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (Tile_arr[x] != 0) return Tile_arr[x];
	return Tile_arr[x] = (Tile_num(x - 1) + Tile_num(x - 2)*2)%10007;
}