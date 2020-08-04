#include <iostream>
#include <algorithm>

using namespace std;
long long arr[200001], ans=0, mid;
int N, C;
//항상 mid에 공유기를 배치하자
long long mybinary_search(long long st,long long ed) // 시작위치, 끝위치
{
	while (st <= ed) {
		long long router = arr[0]; //현재 공유기 위치
		mid = (st + ed) / 2; //임시 공유기 최대 간격
		int num = 1; //현재 공유기 개수
		for (long long i = 1; i < N; i++)
		{
			if (arr[i] - router >= mid)
			{
				num++;
				router = arr[i];
			}
		}

		if (num >= C) //카운팅된 공유기 개수가 설치하고자하는 공유기개수보다 크면 거리를 넓혀보자
		{
			ans = mid;
			st = mid + 1;
		}
		else
			ed = mid - 1;
	}

	return ans;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	
	cout << mybinary_search(0, arr[N-1]);


	return 0;
}