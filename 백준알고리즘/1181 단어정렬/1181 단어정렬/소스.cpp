#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const string& s1, const string& s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;
	else
		return s1.size() < s2.size();
}
int main()
{
	vector<string> v;
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		char c[51];
		scanf("%s", c);
		string str(c);
		v.push_back(str);
	}

	vector<string>::iterator iter; //iterator 는 반복자로 vector를 순환할 때 쓴다. 
	vector<string>::iterator end_iter;

	sort(v.begin(), v.end(), compare);
	end_iter = unique(v.begin(), v.end());

	for (iter = v.begin(); iter != end_iter; iter++)
		printf("%s\n", (*iter).c_str());
	return 0;
}


//koosaga님 코드
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool cmp(string a, string b) {
//	if (a.size() != b.size()) return a.size() < b.size();
//	return a < b;
//}
//
//string s[20005];
//int n;
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> s[i];
//	}
//	sort(s, s + n, cmp);
//	n = (int)(unique(s, s + n) - s);
//	for (int i = 0; i < n; i++) {
//		cout << s[i] << endl;
//	}
//}