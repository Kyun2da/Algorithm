//1. ���� ��ȣ ������ 2���� ���̽��� �ִ� 1.�ٷ� �ڿ� ��ȣ�������°��(������) 2. �踷����� ���ۺκ�
//  �������� ������ ������� �踷��� ������ŭ �����ְ�   �踷����� ���ۺκ��̳����� ���� �踷��� ������ �����ش�.
// �ݴ°�ȣ������ ���� �踷��� ������ �ϳ� ���ش�.

#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;

	int num = 0, cur_line=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (s[i + 1] == ')') { // ������
				num += cur_line;
				i++;
			}
			else { //�踷����� ���ۺκ�
				num += 1;
				cur_line += 1;
			}
		}
		else { //�踷����� ���κ�
			cur_line -= 1;
		}
	}

	cout << num;

	return 0;
}