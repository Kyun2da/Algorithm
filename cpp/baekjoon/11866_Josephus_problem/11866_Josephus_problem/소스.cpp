#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> q;
	int N,K, num;
	cin >> N;
	cin >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	while (q.size() != 0)
	{
		for (int i = 0; i < K - 1; i++)
		{
			num = q.front();
			q.pop();
			q.push(num);
		}
		cout << q.front();
		q.pop();
		if(q.size()!=0)
			cout << ", ";
	}
	cout << ">\n";


	return 0;
}