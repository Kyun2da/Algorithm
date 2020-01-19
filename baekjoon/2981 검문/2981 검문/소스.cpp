#include <cstdio>
#include <algorithm>
#include <vector>


int gcd(int a, int b)
{
	while (b > 0)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

using namespace std;

int main()
{
	int N, arr[101], g;
	vector <int> v;
	scanf("%d", &N);

	for(int i=1; i<=N; i++)
	{
		scanf("%d", &arr[i]);
	}

	g = arr[2] - arr[1];
	for (int i = 3; i <= N; i++)
	{
		g = gcd(arr[i]-arr[i-1], g);
	}

	for (int i = 2; i*i <= g; i++)
	{
		if (g % i == 0)
		{
			v.push_back(i);
			v.push_back(g / i);
		}
	}
	v.push_back(g);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}