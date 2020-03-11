//1. 여는 괄호 나오면 2가지 케이스가 있다 1.바로 뒤에 괄호가나오는경우(레이저) 2. 쇠막대기의 시작부분
//  레이저가 나오면 현재앞의 쇠막대기 개수만큼 더해주고   쇠막대기의 시작부분이나오면 현재 쇠막대기 개수를 더해준다.
// 닫는괄호나오면 현재 쇠막대기 개수를 하나 뺴준다.

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
			if (s[i + 1] == ')') { // 레이저
				num += cur_line;
				i++;
			}
			else { //쇠막대기의 시작부분
				num += 1;
				cur_line += 1;
			}
		}
		else { //쇠막대기의 끝부분
			cur_line -= 1;
		}
	}

	cout << num;

	return 0;
}