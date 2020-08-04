//1.  여는 괄호가 나오면 닫는괄호 나올때까지 푸시
//2.  공백이 나오면 공백 푸시
//3.  단어가 나오면 단어 공백이나 여는괄호나 끝맺음나올때까지 푸시
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
		if (s[i] == '<') {//여는괄호가 나오면 닫는괄호가 나오는곳까지 푸시
			while (s[i] != '>') {
				i++;
			}
			q.push(s.substr(st, i - st + 1));
		}
		else if ((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z')) {//단어가나오면 공백 or 여는괄호 or 끝맺음 까지 푸시
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

	while (!q.empty()) { // 큐에 넣은 단어들을 뒤집어서 큐가 빌때까지 출력
		if(q.front()[0]!='<' && q.front()[0]!=' ') //단어일때만 뒤집는다.
			reverse(q.front().begin(), q.front().end());
		cout << q.front();
		q.pop();
	}

	return 0;
}