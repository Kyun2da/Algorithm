#include <iostream>
#include <stack>
using namespace std;

//스트링으로 구현은 시간초과를 유발함 , 따라서 스택으로 개발해야함 
/*
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int M, idx,size; // M : 명령어 개수, idx : 문자가 들어갈 위치
	string s,add;
	char order; // order : 명령어, add : 삽입할 문자
	cin >> s;
	cin >> M;
	idx = s.size();
	size = s.size();
	while (M--) {
		cin >> order;
		switch (order) {
		case 'L':
			if (idx != 0)
				idx -= 1;
			break;
		case 'D':
			if (idx != size)
				idx += 1;
			break;
		case 'B':
			if (idx != 0) {
				s.erase(idx - 1, 1);
				idx -= 1;
				size -= 1;
			}	
			break;
		case 'P':
			cin >> add;
			s.insert(idx,add);
			idx += 1;
			size += 1;
			break;
		}
		//cout << s << " " << idx <<"\n";
	}

	cout << s;
	return 0;
}
*/


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	stack <char> head, tail; //head는 커서의 왼쪽, tail은 커서의 오른쪽을 의미
	int M, idx, size; // M : 명령어 개수, idx : 문자가 들어갈 위치
	string s, result;
	char order, add; // order : 명령어, add : 삽입할 문자
	cin >> s;
	cin >> M;

	for (int i = 0; i < s.length(); i++) {
		head.push(s[i]);
	}
	while (M--) {
		cin >> order;
		switch (order) {
		case 'L': //커서 왼쪽으로 이동
			if (!head.empty()) {
				tail.push(head.top());
				head.pop();
			}
			break;
		case 'D': //커서 오른쪽으로 이동
			if (!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
			break;
		case 'B': //삭제
			if (!head.empty()) {
				head.pop();
			}
			break;
		case 'P':
			cin >> add;
			head.push(add);
			break;
		}
		//cout << s << " " << idx <<"\n";
	}

	while (!head.empty()) {
		tail.push(head.top());
		head.pop();
	}

	while (!tail.empty()) {
		result += tail.top();
		tail.pop();
	}
	
	cout << result;
	return 0;
}