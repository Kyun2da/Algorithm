#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int arr[20][20];
int ans = 40000;
int N;
void dfs(int people, vector<int> start, vector<int> link) {
	if (people == N) {
		int start_val = 0;
		int link_val = 0;
		if (start.size() == 0)
			return;
		if (link.size() == 0)
			return;
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				start_val += arr[start[i]][start[j]];
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				link_val += arr[link[i]][link[j]];
			}
		}
		ans = min(ans, abs(start_val - link_val));
	}
	else {
		start.push_back(people);
		dfs(people + 1, start, link); //스타트팀에 해당 people이 들어갈때
		start.pop_back();
		link.push_back(people);
		dfs(people + 1, start, link); //링크팀에 해당 people이 들어갈때
		link.pop_back();
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	vector <int> st, li;
	dfs(0, st, li);
	cout << ans << "\n";
	return 0;
}