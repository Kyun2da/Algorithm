#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int channel = 100;
	int N, M;
	int break_button[10];

	cin >> N >> M;
	fill_n(break_button, 10, -1);
	for (int i = 0; i < M; i++) {
		cin >> break_button[i];
	}
	
	int temp = 0;
	int ans = 0;
	int ans1, ans2;
	bool check1, check2;
	int is_ans = abs(N - channel);
	if (break_button[9] != -1)
		ans = abs(N - channel);
	else {
		while (true) {
			string s1 = to_string(N + temp);
			string s2 = to_string(N - temp);
			ans1 = s1.length() + temp; //입력한 번호길이 + (+or-입력횟수)
			ans2 = s2.length() + temp; //입력한 번호길이 + (+or-입력횟수)
			//번호가 있는지 검사
			check1 = true;
			check2 = true;
			for (int i = 0; i < s1.length(); i++) {
				for (int j = 0; j < M; j++) {
					if (s1[i] - '0' == break_button[j]) {
						//고장난 번호가 있으면 break;
						check1 = false;
						break;
					}
				}
			}
			for (int i = 0; i < s2.length(); i++) {
				for (int j = 0; j < M; j++) {
					if (s2[i] - '0' == break_button[j]) {
						//고장난 번호가 있으면 break;
						check2 = false;
						break;
					}
				}
			}
			if (check1)
				ans = ans1;
			if (check2)
				ans = ans2;
			if (check1 && check2) {
				ans = min(ans1, ans2);
			}
			if (check1 || check2)
				break;
			temp++;
		}
	}
	
	cout << min(is_ans,ans) << "\n";

	return 0;
}