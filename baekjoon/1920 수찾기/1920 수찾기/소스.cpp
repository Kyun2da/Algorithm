#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main()
{
	int N,M,num;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (binary_search(arr, arr + N, num))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}