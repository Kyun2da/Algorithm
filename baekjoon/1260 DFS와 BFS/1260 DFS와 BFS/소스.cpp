#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, V, i, j;
stack <int> s;
vector <int> adj[1001];
bool vis[1001];

void dfs() { //비재귀
	fill_n(vis, 1001, 0);
	stack <int> s;
	s.push(V); //맨처음 시작 정점 V를 스택에 넣는다.
	vis[V] = true; //시작 정점을 방문한것을 방문했다고 표시한다.
	while (!s.empty()) { //스택이 비어있지않을때까지 수행
		int cur = s.top(); //현재노드의 위치는 스택의 top
		s.pop(); //스택을 pop한다.
		cout << cur << " "; //스택의 pop한 원소를 출력
		for (int i = 0; i < adj[cur].size(); i++) { //스택의 pop한 원소의 인접 행들을 들어간다.
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			s.push(nxt);
			vis[nxt] = true;
		}
	}
}

void dfs2(int cur) { //재귀
	cout << cur << " ";
	for (int i = 0; i < adj[cur].size(); i++) {
		int nxt = adj[cur][i];
		if (vis[nxt]) continue;
		vis[nxt] = true;
		dfs2(nxt);
	}
}

void bfs() {
	fill_n(vis, 1001, 0);
	queue <int> q;
	q.push(V);    //맨처음 시작 정점 V를 큐에 넣는다.
	vis[V] = true; // 시작원소를 방문
	while (!q.empty()) { // 큐가 비어있지않을 때까지 수행
		int cur = q.front(); //현재 방문 노드를 저장
		q.pop(); //방문 노드를 pop한다
		cout << cur << " "; //방문 노드를 출력
		for (int i = 0; i < adj[cur].size(); i++) { //방문인접리스트의 사이즈만큼 for문 돈다
			int nxt = adj[cur][i]; //방문인접리스트의 노드를 하나씩 방문
			if (vis[nxt]) continue; //이미 방문한 노드면 그냥 지나간다.
			q.push(nxt);  // 방문을 안했다면 큐에 푸시
			vis[nxt] = true; //방문을 했으므로 true로 변환
		}
	}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> V;

	while (M--) {
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	for (int i = 1; i < N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	fill_n(vis, 101, 0);
	vis[V] = true;
	//dfs();
	dfs2(V);
	cout << "\n";
	bfs();

	return 0;
}