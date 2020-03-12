#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//���ÿ��� �ε����� ��
vector<int> v, ans; //v �� �迭 ans �� ��
int arr2[1000001] = { 0, }; //�� ���� ����
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	stack <int> s;
	int N;
	cin >> N;
	v.resize(N+1); ans.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		arr2[v[i]] += 1;
	}

	for (int i = 1; i <= N; i++) {
		while (!s.empty() && arr2[v[s.top()]] < arr2[v[i]]) {
				ans[s.top()] = v[i];
				s.pop();
		}	
		s.push(i);
	}

	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}