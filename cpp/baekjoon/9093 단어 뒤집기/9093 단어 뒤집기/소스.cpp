#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T, st=0; //T = 테스트 케이스, st = 시작 문자위치
	string s;
	queue <string> q;
	cin >> T;
	getline(cin, s);
	while (T--) {
		getline(cin, s);
		for (int i = 0; i <= s.size(); i++) { //큐에 단어 추가
			if (s[i] == ' ' || i==s.size()) {
				q.push(s.substr(st,i-st));
				st = i + 1;
			}
		}

		while (!q.empty()) { // 큐에 넣은 단어들을 뒤집어서 큐가 빌때까지 출력
			reverse(q.front().begin(), q.front().end());
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
		st = 0;
	}

	return 0;
}