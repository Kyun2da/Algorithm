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
		getline(cin, str); //���ڿ� �Է¹���

		if (str == ".") // ���ڿ��� .�̸� stop
			break;

		for (int i = 0; i < str.size(); i++) //���ڿ� ���̸�ŭ ����
		{
			if (str[i] == '(' || str[i] == '[') // '(' �� '[' �� Ǫ��
				s.push(str[i]);
			else if ((str[i] == ')' || str[i] == ']') && s.empty()) // �ݴ°�ȣ�����Դµ� ������ ��������� no
			{
				flag = 1;
				printf("no\n");
				break;
			}
			else if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')) //���°�ȣ�� �ݴ°�ȣ ��ġ�ϸ� yes
				s.pop();
			else if ((str[i] == ']' && s.top() == '(') || (str[i] == ')' && s.top() == '[')) //���°�ȣ�� �ݴ°�ȣ ��ġ���ϸ� no
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