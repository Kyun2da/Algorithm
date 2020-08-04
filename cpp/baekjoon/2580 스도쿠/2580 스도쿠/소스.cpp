#include <iostream>
#include <utility>
using namespace std;

int arr[9][9];
int num = 0; //0�� ����
bool ans = false;
pair <int, int> p[82]; //0�� ����ִ� �ε����迭

bool isHorizon(int i, int number) { //number�� �����߿� ������ false�� ��ȯ
	for (int j = 0; j < 9; j++) {
		if (arr[i][j] == number)
			return true;
	}
	return false;
}

bool isVertical(int j, int number) { //number�� �����߿� ������ true�� ��ȯ
	for (int i = 0; i < 9; i++) {
		if (arr[i][j] == number)
			return true;
	}
	return false;
}

bool isRectangle(int i, int j, int number) { //number�� �ִ� ���簢���� ������ true�� ��ȯ
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

	//0�� �ִ� �ε��� �迭
	int i = p[len].first;
	int j = p[len].second;

	for (int k = 1; k <= 9; k++) {
		if (isHorizon(i, k) || isVertical(j, k) || isRectangle(i, j, k)) //�ϳ��� true�̸� k�� �� �� ����.
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
				num++; //0�� ���� ������Ų��.
				p[num] = { i,j }; //0�� �ִ� �ε��� �ִ´�.
			}
		}
	}

	dfs(1); //ù��° 0�� �ִ� �ڸ�����

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}