#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001] = { 0,1 };

int main() {
    int a, b;
    cin.tie(0);
    ios::sync_with_stdio(0);
    int num;

    //�����佺�׳׽��� ü
    for (int i = 2; i <= sqrt(1000001); i++) {
        if (arr[i] == 0) {
            for (int j = 2; i * j <= 1000001; j++) {
                arr[j * i] = 1;
            }
        }
    }

    //�������� ���� ������ Ȧ���Ҽ��� �� ������ ���� �� �ִ�.
    while (1) {
        cin >> num;
        if (num == 0)
            break;
        bool answer = false;
        for (int i = num - 3; i >= 3; i--) {
            if (arr[i] == 0) {
                for (int j = 3; j <= num-i; j++) {
                    if (arr[j] == 0) {
                        if (i + j == num) {
                            answer = true;
                            cout << num << " = " << j << " + " << i << "\n";
                            break;
                        }
                    }
                }
            }
            if (answer)
                break;
        }
        
    }

	return 0;
}