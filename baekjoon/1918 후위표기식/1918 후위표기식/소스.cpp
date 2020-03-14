#include <iostream>
#include <string>
#include <stack>
using namespace std;

//1. ���ĺ������� ����Ŀ� �ٷ��߰�
//2. '(' �� ������ ���ÿ� �߰�
//3. ')'�� ������ '('�� ���ö����� ���ÿ� �ִ� ������ ���
//4. +, -, *, / �������� ���ÿ� Ǫ��
//5. *�� /�� ������ ������ ��ų� �켱������ ���� �����ڰ� ���ö����� ����Ŀ� �߰�
//6. +�� -�� ������ ������ ��ų� (�� ���ö����� ����Ŀ� �߰�
//7. ������ ������ ��������� ���� ���
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	stack <char> st;
	string s,s2;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { // ���ĺ��� ������ ����Ŀ� �ٷ� �߰�
			s2 += s[i];
		}
		else if (s[i] == '(') { //���°�ȣ������ ���ÿ� Ǫ��
			st.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				s2 += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!st.empty() && st.top() != '(') {
				s2 += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i]==')') {
			while (!st.empty() && st.top() != '(') {
				s2 += st.top();
				st.pop();
			}
			st.pop(); //'('�� pop
		}
	}

	while (!st.empty()) {
		s2 += st.top();
		st.pop();
	}

	cout << s2;
	return 0;
}