#include <iostream>
#include <utility>
using namespace std;

int arr[9][9];
int num = 0; //0의 개수
bool ans = false;
pair <int, int> p[82]; //0이 들어있는 인덱스배열

bool isHorizon(int i, int number) { //number가 가로중에 있으면 false를 반환
	for (int j = 0; j < 9; j++) {
		if (arr[i][j] == number)
			return true;
	}
	return false;
}

bool isVertical(int j, int number) { //number가 세로중에 있으면 true를 반환
	for (int i = 0; i < 9; i++) {
		if (arr[i][j] == number)
			return true;
	}
	return false;
}

bool isRectangle(int i, int j, int number) { //number가 있는 정사각형에 있으면 true를 반환
	for (int m = i / 3 * 3; m <= i / 3 * 3 + 2; m++) {
		for (int n = j / 3 * 3; n <= j / 3 * 3 + 2; n++) {
			if (arr[m][n] == number)
				return true;
		}
	}
	return false;
}

void dfs(int len) {
	if (len == num + 1) {
		ans = true;
		return;
	}

	//0이 있는 인덱스 배열
	int i = p[len].first;
	int j = p[len].second;

	for (int k = 1; k <= 9; k++) {
		if (isHorizon(i, k) || isVertical(j, k) || isRectangle(i, j, k)) //하나라도 true이면 k는 될 수 없다.
			continue;
		arr[i][j] = k;
		dfs(len + 1);
		if (ans == true)
			return;
		arr[i][j] = 0;
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				num++; //0의 개수 증가시킨다.
				p[num] = { i,j }; //0이 있는 인덱스 넣는다.
			}
		}
	}

	dfs(1); //첫번째 0이 있는 자리부터

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}