#include <iostream>

using namespace std;
bool isused1[40]; // column�� �����ϰ� �ִ���
bool isused2[40]; // / ���� �밢���� �����ϰ� �ִ���
bool isused3[40]; // \ ���� �밢���� �����ϰ� �ִ���

int cnt = 0;
int n;
void func(int cur) { // cur��° row�� ���� ��ġ�� ������
	if (cur == n) { // N���� ���µ� �����ߴٸ�
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) { // (cur, i)�� ���� ���� ����
		if (isused1[i] or isused2[i + cur] or isused3[cur - i + n - 1]) // column�̳� �밢�� �߿� ������ �ִٸ�
			continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
}