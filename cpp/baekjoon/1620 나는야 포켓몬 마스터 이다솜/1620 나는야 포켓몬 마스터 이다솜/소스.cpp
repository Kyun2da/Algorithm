#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M;
	map <string, int> m;
	map <int, string> m2;
	map <string, int>::iterator iter;
	map <int, string>::iterator iter2;
	string s;
	int num;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		m.insert(pair<string,int>(s, i));
		m2.insert(pair<int, string>(i, s));
	}

	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			num = atoi(s.c_str());
			cout << m2.find(num)->second << "\n";
		}
		else
			cout << m.find(s)->second<< "\n";
	}

	return 0;
}