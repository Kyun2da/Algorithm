#include <iostream>
#include <stack>
using namespace std;
//스택을 사용하면 모두 끝까지 갈필요가없으므로 n제곱에서 n으로 시간복잡도가 감소됨
int main()
{
	int N;
	int arr[1000001];
	int res[1000001];
	stack <int> s;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && arr[s.top()] < arr[i]) //arr[i]가 top보다 클때까지 계속 pop하면서 결과 배열에 넣는다.
		{
			res[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) //마지막에 정리되지못한 수들은 -1로 보면됨
	{
		res[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) 
	{
		cout << res[i] << ' ';
	}
	return 0;
}