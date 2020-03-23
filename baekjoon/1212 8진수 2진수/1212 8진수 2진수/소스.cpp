#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	string arr[8] = { "000","001","010","011","100","101","110","111" };
	string s;
	string ans;
	int num;
	cin >> s;
	
	num = s[0] - '0';
	ans.append(arr[num]);
	if (s[0] == '0' || s[0]=='1') ans.replace(0, 2, "");
	else if (s[0] == '2' || s[0] == '3') ans.replace(0, 1, "");
	for (int i = 1; i < s.length(); i++) {
		num = s[i] - '0';
		ans += arr[num];
	}

	cout << ans;

	return 0;
}