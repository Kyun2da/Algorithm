#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue <int> pq;

	cout << "empty : " << pq.empty() << endl;
	pq.push(20);
	cout << "empty : " << pq.empty() << endl;
	cout << pq.top() << endl;

	pq.push(10);
	cout <<"top : " << pq.top() << endl;

	pq.push(30);
	cout << "top : " << pq.top() << endl;

	pq.push(50);
	pq.push(40);
	cout << "top : " << pq.top() << endl;
	cout << "size : " << pq.size() << endl;

	pq.pop();
	cout << "top : " << pq.top() << endl;

	while (!pq.empty()) {
		cout << "top : " << pq.top() << endl;
		pq.pop();
	}
	return 0;
}