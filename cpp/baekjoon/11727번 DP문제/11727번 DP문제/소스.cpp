#include <iostream>
using namespace std;
int Tile_arr[1001];

int Tile_num(int x);
//i번째 타일의 경우는 i-1번째에서 1x2짜리 타일 한개붙이는 경우와 i-2번째에서 2x1 타일 두개 붙이는 경우와 2x2 타일 한개를 붙이는 경우
//즉 점화식은 An-1+An-2*2
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