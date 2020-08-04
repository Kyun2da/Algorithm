#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s;
	int lower_num, upper_num, number_num, blank_num;

	while (1) {
		lower_num = 0;
		upper_num = 0;
		number_num = 0;
		blank_num = 0;
		getline(cin, s);
		if (s.size() ==0) break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				lower_num++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				upper_num++;
			}
			else if (s[i] == ' ') {
				blank_num++;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				number_num++;
			}
		}
		cout << lower_num << " " << upper_num << " " << number_num << " " << blank_num << "\n";
	}


	return 0;
}