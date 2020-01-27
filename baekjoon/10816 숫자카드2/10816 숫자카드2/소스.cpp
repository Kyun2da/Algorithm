#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int arr2[500001];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}
	
	sort(arr, arr + n);
	
	for (int i = 0; i < m; i++)
	{
		cout << upper_bound(arr, arr + n, arr2[i]) - lower_bound(arr, arr + n, arr2[i]) << " ";
	}
	return 0;
}