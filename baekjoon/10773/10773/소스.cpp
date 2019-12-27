#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> s;

	int N,num,sum=0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}