#include <iostream>

using namespace std;

int arr[257] = { 0, }; //�� �迭�� �ε����� ���� ���̸� �ǹ���
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

	for (int i = min_num; i <= max_num; i++) { //i�� ���� ���� ����
		//min_num���� max_num���� ���̸� ���߸� ���� ���� ������.
		temp = B; //�κ��丮 �ʱ�ȭ
		second = 0; //�� �ʱ�ȭ
		for (int j = min_num; j <= max_num; j++) { // j�� ���� ������
			if (i > j) { //i�� j���� ũ�� ���� �׾ƾߵ� 1��
				temp -= arr[j] * (i-j);
				second += arr[j] * (i-j);
			}
			else if (i < j) { // i�� j���� ������ ���� ���. 2��
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