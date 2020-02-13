#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
int arr[21][21];
vector <int> start, link;
int start_sum = 0;
int link_sum = 0;
int ans=2147483647;
int start_first, start_second, link_first, link_second;
void dfs(int length) { //length번을 넣는다
	if (start.size() > N / 2 || link.size() > N / 2)
		return;
	if (N/2 == start.size() && N/2 == link.size()) {
		start_sum = 0;
		link_sum = 0;

		for (int i = 0; i < N / 2 -1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				start_first = start[i];
				start_second = start[j];
				
				start_sum += arr[start_first][start_second] + arr[start_second][start_first];

				link_first = link[i];
				link_second = link[j];

				link_sum += arr[link_first][link_second] + arr[link_second][link_first];
			}
		}

		if (ans > abs(start_sum - link_sum))
			ans = abs(start_sum - link_sum);
		return;
	}
	start.push_back(length);
	dfs(length + 1); //몇번의 팀을 정하러 가자
	start.pop_back();

	link.push_back(length);
	dfs(length + 1);
	link.pop_back();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(1);

	cout << ans;

	return 0;
}