#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

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

	sort(v.begin(), v.end());

	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}