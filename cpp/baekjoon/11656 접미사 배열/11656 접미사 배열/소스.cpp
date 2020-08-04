#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string temp;
	vector <string> s;

	cin >> temp;
	int len = temp.length();
	for (int i = 1; i <= len; i++) {
		s.push_back(temp.substr(len-i, i));
		
	}
	sort(s.begin(), s.end());
	
	for (int i = 0; i < len; i++) {
		cout << s[i] << "\n";
	}
	return 0;
}