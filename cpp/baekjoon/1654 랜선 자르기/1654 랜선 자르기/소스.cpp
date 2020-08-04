#include <iostream>
#include <algorithm>

using namespace std;
long long  arr[10000];
long long K, N; //K : 랜선의 개수, N : 필요한 랜선의 개수
long long start = 0, ed, mid, ans = 0, sum = 0;

long long myBinarySearch(long long st, long long ed)
{
	if (st > ed)
		return ans;
	sum = 0;
	mid = (st + ed) / 2;
	for (int i = 0; i < K; i++)
		sum += arr[i] / mid;
	//cout << "st는 : " << st << "mid는 : " << mid  <<"ed는 : " << ed << endl;
	if (sum >= N) // 개수가 크거나 같으면
	{
		ans = mid;
		return myBinarySearch(mid+1, ed);
	}
	else // 개수가 작으면
		return myBinarySearch(st, mid-1);
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> arr[i];

	sort(arr, arr + K);
	ed = arr[K - 1];
	mid = arr[K - 1];
	
	for (int i = 0; i < K; i++) // 초반에 큰수가 나오면
		sum += arr[i] / ed;
	if (sum == arr[K-1])
	{
		cout << ed;
		return 0;
	}

	cout << myBinarySearch(1, arr[K-1]);
	return 0;
}