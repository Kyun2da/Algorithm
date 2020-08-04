#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	int N,num;
	cin >> N;

	string s;
	queue <int> q;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "size") {
			cout << q.size()<<"\n";
		}
		else if (s == "empty") {
			cout << q.empty()<<"\n";
		}
		else if (s == "front") {
			if (!q.empty())
			{
				cout << q.front() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "back") {
			if (!q.empty())
			{
				cout << q.back() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else
			continue;
	}

	return 0;
}