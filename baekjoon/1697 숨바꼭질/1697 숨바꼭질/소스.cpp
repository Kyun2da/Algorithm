#include <iostream>
#include <queue>

using namespace std;
int arr[100001] = {0, };

bool isInside(int x) {
	return (x >= 0 && x <= 100000);
}
int main() {

	queue <int> q;
	int N, K;
	cin >> N >> K;
	q.push(N);
	arr[N] = 1;
	
	
	while (arr[K]==0) {
		int cur = q.front();
		q.pop();
		//cout << cur << "\n";
		if (isInside(cur-1) && arr[cur - 1] == 0) {
			q.push(cur - 1);
			arr[cur - 1] = arr[cur] + 1;
		}
		if (isInside(cur + 1) && arr[cur + 1] == 0) {
			q.push(cur + 1);
			arr[cur + 1] = arr[cur] + 1;
		}
		if (isInside(cur *2) && arr[cur * 2] == 0) {
			q.push(cur * 2);
			arr[cur *2] = arr[cur] + 1;
		}
	}
	
	cout << arr[K] - 1;
	return 0;
}