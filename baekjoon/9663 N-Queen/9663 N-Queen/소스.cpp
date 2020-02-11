#include <iostream>

using namespace std;

int N, cnt=0;
int isused1[30]; // - 검사
int isused2[30]; // / 검사
int isused3[30]; // \ 검사

void func(int cur) { //cur행에 말을 놓는다.
	if (cur == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1])
			continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + N - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + N - 1] = 0;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N;

	func(0);
	cout << cnt;
	return 0;
}