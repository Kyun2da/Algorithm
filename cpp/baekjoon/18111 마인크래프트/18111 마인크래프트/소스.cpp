#include <iostream>

using namespace std;

int arr[257] = { 0, }; //각 배열의 인덱스는 땅의 높이를 의미함
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M, B, num, ans=2e9, temp, second, height=0;
	int max_num=0, min_num = 256;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			arr[num] += 1;
			if (max_num < num)
				max_num = num;
			if (min_num > num)
				min_num = num;
		}
	}

	for (int i = min_num; i <= max_num; i++) { //i는 맞출 땅의 높이
		//min_num부터 max_num까지 높이를 맞추며 땅을 고르게 만들어본다.
		temp = B; //인벤토리 초기화
		second = 0; //초 초기화
		for (int j = min_num; j <= max_num; j++) { // j는 현재 땅높이
			if (i > j) { //i가 j보다 크면 땅을 쌓아야됨 1초
				temp -= arr[j] * (i-j);
				second += arr[j] * (i-j);
			}
			else if (i < j) { // i가 j보다 작으면 땅을 깐다. 2초
				temp += arr[j] * (j - i);
				second += arr[j] * (j - i) * 2;
			}
		}
		if (temp >= 0 && second < ans) {
			ans = second;
			height = i;
		}
		else if (temp >= 0 && second == ans && i > height) {
			ans = second;
			height = i;
		}
	}
	
	cout << ans <<" " << height;
	return 0;
}