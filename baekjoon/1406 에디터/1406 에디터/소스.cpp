#include <iostream>
#include <stack>
using namespace std;

//��Ʈ������ ������ �ð��ʰ��� ������ , ���� �������� �����ؾ��� 
/*
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int M, idx,size; // M : ��ɾ� ����, idx : ���ڰ� �� ��ġ
	string s,add;
	char order; // order : ��ɾ�, add : ������ ����
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

	stack <char> head, tail; //head�� Ŀ���� ����, tail�� Ŀ���� �������� �ǹ�
	int M, idx, size; // M : ��ɾ� ����, idx : ���ڰ� �� ��ġ
	string s, result;
	char order, add; // order : ��ɾ�, add : ������ ����
	cin >> s;
	cin >> M;

	for (int i = 0; i < s.length(); i++) {
		head.push(s[i]);
	}
	while (M--) {
		cin >> order;
		switch (order) {
		case 'L': //Ŀ�� �������� �̵�
			if (!head.empty()) {
				tail.push(head.top());
				head.pop();
			}
			break;
		case 'D': //Ŀ�� ���������� �̵�
			if (!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
			break;
		case 'B': //����
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