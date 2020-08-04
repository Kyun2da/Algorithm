#include <iostream>
#include <algorithm>
using namespace std;
long long N, M, arr[1000000], ans,mid, sum, mx; //sum�� �����������ϴ� ������ ��

int myBinarySearch(int st, int ed)
{
	if (st > ed)
		return ans;
	mid = (st + ed) / 2;
	sum = 0;
	for (long long i = 0; i < N; i++)
	{
		if(arr[i]-mid>=0)
			sum += arr[i] - mid;
	}
	//cout << "st�� : " << st << " mid�� : " << mid << " ed�� : " << ed << endl;
	if (sum >= M)
	{
		ans = mid;
		return myBinarySearch(mid+1, ed);
	}
	else
		return myBinarySearch(st, mid-1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M; //N : ������ ��, M : ����̰� ������ ���������� �ϴ� ������ ����
	for (long long i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (mx < arr[i])
			mx = arr[i];
	}

	
	cout << myBinarySearch(1, mx);

	return 0;
}