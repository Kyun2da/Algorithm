#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1)
	{
		string num;
		cin >> num;
		if (num == "0")
			break;
		if (num.size() == 1) {
			cout << "yes\n";
			continue;
		}
		for (int i = 0; i < num.size() / 2; i++) {
			if (num[i] != num[num.size() - i - 1]) {
				cout << "no\n";
				break;
			}
			else if (i == num.size()/2 - 1)
				cout << "yes\n";
		}
	}


	return 0;
}