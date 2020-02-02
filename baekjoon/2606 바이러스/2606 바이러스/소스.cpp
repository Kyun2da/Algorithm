#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int sum = 0;

stack <int> s;
vector <int> adj[101];
int vis[101] = { 0, };
void dfs(int cur) {
	for (int i = 0; i < adj[cur].size(); i++) {
		int nxt = adj[cur][i];
		if (vis[nxt]) continue;
		vis[nxt] = true;
		sum++;
		dfs(nxt);
	}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	
	
	int v, e, i, j;
	cin >> v >> e;

	while(e--){
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for (int i = 1; i <= v; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	vis[1] = true;
	dfs(1);
	cout << sum;
	return 0;
}