#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, K;
	deque <int> dq;
	cin >> N >> K;

	for(int i=1; i<=N; i++) {
		dq.push_back(i);
	}
	cout << "<";
	while (!dq.empty()) {
		for (int i = 0; i < K - 1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front();
		if (dq.size() > 1)
			cout << ", ";
		dq.pop_front();
	}
	cout << ">";
	return 0;
}