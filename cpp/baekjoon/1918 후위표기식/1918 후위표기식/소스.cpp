#include <iostream>
#include <string>
#include <stack>
using namespace std;

//1. 알파벳나오면 결과식에 바로추가
//2. '(' 가 나오면 스택에 추가
//3. ')'가 나오면 '('가 나올때까지 스택에 있는 연산자 출력
//4. +, -, *, / 가나오면 스택에 푸시
//5. *나 /가 나오면 스택이 비거나 우선순위가 낮은 연산자가 나올때까지 결과식에 추가
//6. +나 -가 나오면 스택이 비거나 (이 나올때까지 결과식에 추가
//7. 나머지 스택이 비어있을때 까지 출력
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	stack <char> st;
	string s,s2;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { // 알파벳이 나오면 결과식에 바로 추가
			s2 += s[i];
		}
		else if (s[i] == '(') { //여는괄호나오면 스택에 푸시
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
			st.pop(); //'('도 pop
		}
	}

	while (!st.empty()) {
		s2 += st.top();
		st.pop();
	}

	cout << s2;
	return 0;
}