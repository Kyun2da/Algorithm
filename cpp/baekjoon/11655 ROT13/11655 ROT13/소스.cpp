#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] >= 110)
				s[i] -= 13;
			else
				s[i] += 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] >= 78)
				s[i] -= 13;
			else
				s[i] += 13;
		}
	}

	cout << s;

	return 0;
}