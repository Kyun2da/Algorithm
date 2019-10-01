#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
	return a.first < b.first;
}
int main()
{
	
	int n;
	int a;
	string s;
	cin >> n;
	vector <pair<int, string>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(),compare);
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
	return 0;
}