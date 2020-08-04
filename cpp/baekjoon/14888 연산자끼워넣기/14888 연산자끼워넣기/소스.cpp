#include <iostream>

using namespace std;
int N;
int arr[12]; // arr[1]부터 최대 11개
int oper[11]; //0 1 2 3 순서로 + - * /
bool vis[11]; //오퍼레이터 방문 여부
int oper_num; //operator의 각 연산 개수
int num=1;
int max_num = -1000000000;
int min_num = 1000000000;

void dfs(int length, int sum) {
	if (length == N-1) {
		if (max_num < sum)
			max_num = sum;
		if (min_num > sum)
			min_num = sum;
		return;
	}

	for (int i = 1; i <= N-1; i++) {
		if (!vis[i]) {
			vis[i] = true;
			if (oper[i] == 0) {	
				dfs(length + 1, sum + arr[length + 2]);
			}
			else if (oper[i] == 1) {
				dfs(length + 1, sum - arr[length + 2]);
			}
			else if (oper[i] == 2) {
				dfs(length + 1, sum * arr[length + 2]);
			}
			else {
				dfs(length + 1, sum / arr[length + 2]);
			}
			vis[i] = false;
		}	
	}
	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++) { //oper배열에 연산자를 순서대로 넣는다.
		cin >> oper_num;
		for (int j = 0; j < oper_num; j++) {
			if (i == 0)
				oper[num] = 0;
			else if (i == 1)
				oper[num] = 1;
			if (i == 2)
				oper[num] = 2;
			if (i == 3)
				oper[num] = 3;
			num++;
		}
	}
	
	/*for (int i = 1; i <= N - 1; i++)
		cout << oper[i] << " ";
	cout << "\n";*/

	for (int i = 1; i <= N - 1; i++) {
		vis[i] = true;
		if (oper[i] == 0) {
			dfs(1, arr[1] + arr[2]);
		}
		else if (oper[i] == 1) {
			dfs(1, arr[1] - arr[2]);
		}
		else if (oper[i] == 2) {
			dfs(1, arr[1] * arr[2]);
		}
		else {
			dfs(1, arr[1] / arr[2]);
		}
		vis[i] = false;
	}
	
	cout << max_num << "\n" << min_num;

	return 0;
}