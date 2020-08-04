#include <iostream>

using namespace std;

int main() {
	string s1, s2, s3, s4;
	long long int a, b;
	cin >> s1 >> s2 >> s3 >> s4;
	s1.append(s2);
	s3.append(s4);

	a = atof(s1.c_str());
	b = atof(s3.c_str());
	
	cout << a + b;

	return 0;
}