#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main()
{
	vector<pair<int, int> > v;

	int num;
	scanf("%d", &num);
	int a, b;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}