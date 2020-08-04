#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T, st=0; //T = �׽�Ʈ ���̽�, st = ���� ������ġ
	string s;
	queue <string> q;
	cin >> T;
	getline(cin, s);
	while (T--) {
		getline(cin, s);
		for (int i = 0; i <= s.size(); i++) { //ť�� �ܾ� �߰�
			if (s[i] == ' ' || i==s.size()) {
				q.push(s.substr(st,i-st));
				st = i + 1;
			}
		}

		while (!q.empty()) { // ť�� ���� �ܾ���� ����� ť�� �������� ���
			reverse(q.front().begin(), q.front().end());
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
		st = 0;
	}

	return 0;
}