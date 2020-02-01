#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	int N,num, abs_num;
	cin >> N;

	while (N--) {
		cin >> num;
		abs_num = abs(num);
		
		if (num == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else {
				cout  << pq.top().second << "\n";
				pq.pop();
			}
			
		}
		else {
			pq.push(pair<int, int>(abs_num, num));
		}
	}

	return 0;
}