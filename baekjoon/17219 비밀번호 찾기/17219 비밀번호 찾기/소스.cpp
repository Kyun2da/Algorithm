#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s1, s2;
	map <string, string> m;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		m.insert(pair<string, string>(s1, s2));	
	}

	for (int i = 0; i < M; i++) {
		cin >> s1;
		cout << m.find(s1)->second << "\n";
	}

	return 0;
}