#include <iostream>
#include <algorithm>

using namespace std;
long long  arr[10000];
long long K, N; //K : ������ ����, N : �ʿ��� ������ ����
long long start = 0, ed, mid, ans = 0, sum = 0;

long long myBinarySearch(long long st, long long ed)
{
	if (st > ed)
		return ans;
	sum = 0;
	mid = (st + ed) / 2;
	for (int i = 0; i < K; i++)
		sum += arr[i] / mid;
	//cout << "st�� : " << st << "mid�� : " << mid  <<"ed�� : " << ed << endl;
	if (sum >= N) // ������ ũ�ų� ������
	{
		ans = mid;
		return myBinarySearch(mid+1, ed);
	}
	else // ������ ������
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
	
	for (int i = 0; i < K; i++) // �ʹݿ� ū���� ������
		sum += arr[i] / ed;
	if (sum == arr[K-1])
	{
		cout << ed;
		return 0;
	}

	cout << myBinarySearch(1, arr[K-1]);
	return 0;
}