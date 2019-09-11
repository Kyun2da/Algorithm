#include <iostream>
using namespace std;

//점화식을 도출해 보면 An=An-1+An-2 라는 것을 알 수 있다.
int Tile_Arr[1001] = { 0 };
int Tile_num(int x);

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
	if (x == 2) return 2;
	if (Tile_Arr[x] != 0) return Tile_Arr[x];
	return Tile_Arr[x] = (Tile_num(x - 1) + Tile_num(x - 2)) % 10007; //10007로 나눈 나머지가 필요하므로 이 조건이 들어가야 한다!
}