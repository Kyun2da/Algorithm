#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	double arr[27];
	int N;
	int num;
	double cal1, cal2;
	string s;
	stack <double> st;
	cin >> N;
	cin >> s;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			num = s[i] - 65;
			st.push(arr[num]);
		}
		else {
			cal2 = st.top();
			st.pop();
			cal1 = st.top();
			st.pop();
			switch (s[i]) {
			case '+': st.push(cal1 + cal2);
				break;
			case '-': st.push(cal1 - cal2);
				break;
			case '*': st.push(cal1 * cal2);
				break;
			case '/': st.push(cal1 / cal2);
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}