#include <iostream>

using namespace std;
int arr[1000001] = { 0,1 }; //1은소수가 아니므로 1로
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2; i * j <= 1000000; j++)
		{
			arr[j * i] = 1;
		}
	}

	int T,num,ans;
	cin >> T;
	while (T--) {
		cin >> num;
		ans = 0;
		for (int i = 2; i <= num / 2; i++) {
			if (arr[i] == 0 && arr[num - i] == 0)
				ans++;
		}
		cout << ans << "\n";
	}


	return 0;
}