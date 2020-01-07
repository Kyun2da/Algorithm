#include <iostream>
#include <algorithm>
using namespace std;
//동적프로그래밍
//현재의 집을 어디에 칠하느냐에 따라 최솟값이 다르다. 현재의 집을 칠한 색깔 3개중에 가장 작은 합을 구하면 된다.
//3번째 집에 빨강을 칠했다면 두번째 칠한 집의 초록색의 최솟값과 파랑색의 최솟값중 작은 값을 더하면 된다. 그것이 3번째 집에 빨강을 칠했을 때의 최솟값이다.
//첫번째 집만 있다고 가정하면 이 집의 최솟값은 그냥 첫번째 집의 색깔 비용이 색깔마다의 최소 비용이 된다.
//두번째 집을 빨강을 칠하면 이 최솟값은 min(첫번째집이 초록을 칠했을때, 첫번째 집이 파랑을칠했을때)+두번째집의 빨강비용이 최솟값이 된다.
// 이런식으로 생각해보면 결국 현재 집의 색깔마다의 최솟값은 min(n-1집의 다른 두 색깔의 값) + 현재 집의 색깔 비용 이된다.
int main()
{
	int house_num, color_table[1001][3], r, g, b, total_table[1001][3];

	cin >> house_num;

	for (int i = 1; i <= house_num; i++)
	{
		cin >> r >> g >> b;
		color_table[i][0] = r;
		color_table[i][1] = g;
		color_table[i][2] = b;
	}

	total_table[1][0] = color_table[1][0];
	total_table[1][1] = color_table[1][1];
	total_table[1][2] = color_table[1][2];

	for (int i = 2; i <= house_num; i++)
	{
		total_table[i][0] = min(total_table[i - 1][1], total_table[i - 1][2]) + color_table[i][0];
		total_table[i][1] = min(total_table[i - 1][2], total_table[i - 1][0]) + color_table[i][1];
		total_table[i][2] = min(total_table[i - 1][0], total_table[i - 1][1]) + color_table[i][2];
	}

	cout << min(total_table[house_num][0], min(total_table[house_num][1], total_table[house_num][2])) << endl;
	return 0;
}