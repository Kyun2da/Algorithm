#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int N, M;
	string s2;
	vector <string> v;
	vector <string>::iterator iter;
	
	map <string, int> m;
	map <string, int> m2;
	map <string, int>::iterator iter2;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s2;
		v.push_back(s2);
	}

	for (int i = 0; i < M; i++) {
		cin >> s2;
		m.insert(pair<string,int> (s2, i));
	}

	for (iter = v.begin(); iter != v.end(); iter++) {
		if (m.find(*iter) != m.end()) {
			m2.insert(pair<string,int> (*iter,0));
		}
	}
	
	cout << m2.size() << "\n";

	for (iter2 = m2.begin(); iter2 != m2.end(); iter2++) {
		cout << iter2->first << "\n";
	}
	return 0;
}