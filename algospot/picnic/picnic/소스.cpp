//소풍 문제
//완전탐색기법 사용
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int n;
bool areFriends[10][10];
void init_areFriends() {  //초기화
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			areFriends[i][j] = false;
		}
	}
}
int countPairing(bool taken[10], size_t stu_num) {
	int firstFree = -1;
	for (int i = 0; i < stu_num; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < stu_num; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairing(taken, stu_num);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	bool taken[10] = { false, };
	for (int i = 0; i < n; ++i) {
		init_areFriends();
		int numberStudent, numberPairing;
		cin >> numberStudent;
		cin >> numberPairing;
		for (int j = 0; j < numberPairing; j++) {
			int prev;
			int aft;
			cin >> prev >> aft;
			areFriends[prev][aft] = true;
		}
		cout << countPairing(taken, numberStudent)<< endl;
	}
	return 0;
}