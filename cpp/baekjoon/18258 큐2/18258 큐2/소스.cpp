#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue <int> q;
	string s;
	int N,num;
	cin >> N;

	while (N--) {
		cin >> s;

		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else{
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}

	}



	return 0;
}