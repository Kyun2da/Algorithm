#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int alpha[26] = { 0, };

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}
	return 0;
}