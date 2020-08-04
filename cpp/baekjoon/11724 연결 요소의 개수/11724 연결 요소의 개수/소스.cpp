#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> adj[1001];
bool vis[1001] = { 0, };

void dfs(int n) {
	stack <int> s;

	s.push(n);
	vis[n] = true;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			s.push(nxt);
			vis[nxt] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M; // 정점의 개수, 간선의 개수
	int i, j, ans=0;
	cin >> N >> M;

	while (M--) {
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			dfs(i);
			ans++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}