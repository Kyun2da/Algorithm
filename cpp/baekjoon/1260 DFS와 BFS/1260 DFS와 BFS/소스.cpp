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

void dfs() { //�����
	fill_n(vis, 1001, 0);
	stack <int> s;
	s.push(V); //��ó�� ���� ���� V�� ���ÿ� �ִ´�.
	vis[V] = true; //���� ������ �湮�Ѱ��� �湮�ߴٰ� ǥ���Ѵ�.
	while (!s.empty()) { //������ ����������������� ����
		int cur = s.top(); //�������� ��ġ�� ������ top
		s.pop(); //������ pop�Ѵ�.
		cout << cur << " "; //������ pop�� ���Ҹ� ���
		for (int i = 0; i < adj[cur].size(); i++) { //������ pop�� ������ ���� ����� ����.
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			s.push(nxt);
			vis[nxt] = true;
		}
	}
}

void dfs2(int cur) { //���
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
	q.push(V);    //��ó�� ���� ���� V�� ť�� �ִ´�.
	vis[V] = true; // ���ۿ��Ҹ� �湮
	while (!q.empty()) { // ť�� ����������� ������ ����
		int cur = q.front(); //���� �湮 ��带 ����
		q.pop(); //�湮 ��带 pop�Ѵ�
		cout << cur << " "; //�湮 ��带 ���
		for (int i = 0; i < adj[cur].size(); i++) { //�湮��������Ʈ�� �����ŭ for�� ����
			int nxt = adj[cur][i]; //�湮��������Ʈ�� ��带 �ϳ��� �湮
			if (vis[nxt]) continue; //�̹� �湮�� ���� �׳� ��������.
			q.push(nxt);  // �湮�� ���ߴٸ� ť�� Ǫ��
			vis[nxt] = true; //�湮�� �����Ƿ� true�� ��ȯ
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