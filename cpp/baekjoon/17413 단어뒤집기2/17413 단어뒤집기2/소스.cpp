//1.  ���� ��ȣ�� ������ �ݴ°�ȣ ���ö����� Ǫ��
//2.  ������ ������ ���� Ǫ��
//3.  �ܾ ������ �ܾ� �����̳� ���°�ȣ�� ���������ö����� Ǫ��
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int st = 0;
	string s, temp;
	queue <string> q;

	getline(cin, s);

	for (int i = 0; i <= s.size(); i++) {	
		st = i;
		if (s[i] == '<') {//���°�ȣ�� ������ �ݴ°�ȣ�� �����°����� Ǫ��
			while (s[i] != '>') {
				i++;
			}
			q.push(s.substr(st, i - st + 1));
		}
		else if ((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z')) {//�ܾ������ ���� or ���°�ȣ or ������ ���� Ǫ��
			while (s[i] != '<' && s[i] != ' ' && s[i]!='\0') {
				i++;
			}
			q.push(s.substr(st, i - st));
			i--;
		}
		else if (s[i] == ' ') {
			q.push(" ");
		}
	}

	while (!q.empty()) { // ť�� ���� �ܾ���� ����� ť�� �������� ���
		if(q.front()[0]!='<' && q.front()[0]!=' ') //�ܾ��϶��� �����´�.
			reverse(q.front().begin(), q.front().end());
		cout << q.front();
		q.pop();
	}

	return 0;
}