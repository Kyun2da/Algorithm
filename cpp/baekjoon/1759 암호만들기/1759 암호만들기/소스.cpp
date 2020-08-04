#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	char arr[15];
	char ans[15];
	int L, C;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	int chk[15];
	for (int i = 0; i < L; i++)
		chk[i] = 1;
	for (int i = L; i < C; i++) {
		chk[i] = 0;
	}
	do
	{
		int idx = 0;
		int za = 0;
		int mo = 0;
		for (int i = 0; i < C; i++) {
			if (!chk[i]) continue;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				mo++;
			else
				za++;
			ans[idx] = arr[i];
			idx++;
		}
		if (za < 2 || mo < 1) continue;
		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
	} while (prev_permutation(chk, chk + C));
	return 0;
}