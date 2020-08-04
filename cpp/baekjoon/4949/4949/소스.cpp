#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	stack <char> s;
	int flag = 0;
	while (1)
	{
		flag = 0;
		getline(cin, str); //문자열 입력받음

		if (str == ".") // 문자열이 .이면 stop
			break;

		for (int i = 0; i < str.size(); i++) //문자열 길이만큼 돈다
		{
			if (str[i] == '(' || str[i] == '[') // '(' 나 '[' 는 푸시
				s.push(str[i]);
			else if ((str[i] == ')' || str[i] == ']') && s.empty()) // 닫는괄호가나왔는데 스택이 비어있으면 no
			{
				flag = 1;
				printf("no\n");
				break;
			}
			else if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')) //여는괄호와 닫는괄호 일치하면 yes
				s.pop();
			else if ((str[i] == ']' && s.top() == '(') || (str[i] == ')' && s.top() == '[')) //여는괄호와 닫는괄호 일치안하면 no
			{
				flag = 1;
				printf("no\n");
				break;
			}
			else
				continue;
		}

		if (flag != 1)
		{
			if (!s.empty())
			{
				printf("no\n");

			}
			else
				printf("yes\n");
		}

		while (!s.empty())
			s.pop();
	}


	return 0;
}