//계단을 현재위치에 서있다고 가정할 때 한칸전에서 오는 방법과 두칸전에서 오는 방법이있다.
//그 중 한칸 전에서오는것은 두칸전에서는 오면 안되므로 현재위치의 가치+한칸 전위치의 가치+세칸전까지의 가장 비싼 가치라고 할 수 있다.
//두 칸 전에서오는것은 현재위치의 가치 + 두칸 전위치 까지의 가장 비싼 가치라고 할 수 있다.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, num;
	int stair[301];
	int total[301];

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		stair[i] = num;
	}

	total[1] = stair[1];
	total[2] = stair[1] + stair[2];
	total[3] = stair[3] + max(stair[1], stair[2]);

	for (int i = 4; i <= N; i++)
	{
		total[i] = max(stair[i] + stair[i - 1] + total[i - 3], stair[i] + total[i - 2]);
	}

	cout << total[N] << endl;

	return 0;
}