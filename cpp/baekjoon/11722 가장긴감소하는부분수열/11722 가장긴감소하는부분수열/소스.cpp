#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, ans=0, num;
	vector <int> v;
	cin >> N;

	while (N--) {
		cin >> num;
		if (v.empty() || v.back() > num) {
			v.push_back(num);
			ans++;
		}
		else {
			vector <int>::iterator it = lower_bound(v.begin(), v.end(), num, greater<int>());
			*it = num;
		}
	}
	
	/*for (int i = 0; i < ans; i++) {
		cout << v[i] << " ";
	}*/
	cout << ans;
	return 0;
}