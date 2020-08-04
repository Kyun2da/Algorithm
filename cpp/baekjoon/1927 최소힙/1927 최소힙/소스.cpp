#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	priority_queue <int, vector<int>,greater<int>> pq;
	int N, num;
	cin >> N;
	while (N--) {
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(num);
	}


	return 0;
}