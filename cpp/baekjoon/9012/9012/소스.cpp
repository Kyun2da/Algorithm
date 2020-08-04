#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack <char> s;
	string str;
	int N,flag=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		flag = 0;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
				s.push(')');
			else
			{
				if (!s.empty())
					s.pop();
				else
				{
					cout << "NO\n";
					while (!s.empty())
						s.pop();
					flag=1;
					break;
				}
			}
		}
		if (flag != 1)
		{
			if (s.empty())
				cout << "YES\n";
			else
			{
				cout << "NO\n";
				while (!s.empty())
					s.pop();
			}
		}
	}
	return 0;
}