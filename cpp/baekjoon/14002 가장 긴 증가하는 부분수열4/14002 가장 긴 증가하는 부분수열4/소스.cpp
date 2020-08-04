#include <iostream>
#include <stack>

using namespace std;

int arr[1001];
int lis[1001];
pair<int, int> ans[1001]; // first :: lis가 될 수 있는 위치, second :: 해당하는 값
stack<int> s;

int _lower_bound(int start, int end, int target)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (lis[mid] < target)
			start = mid + 1;

		else
			end = mid;
	}

	return end + 1;
}

int main()
{
	int n;  //수열 n의 크기
	cin >> n;

	for (int i = 0; i < n; i++) //수열의 배열
		cin >> arr[i];

	int pLis = 0, pArr = 1;

	lis[pLis] = arr[0];
	ans[0].first = 0;
	ans[0].second = arr[0];

	while (pArr < n)
	{
		if (lis[pLis] < arr[pArr])
		{
			lis[++pLis] = arr[pArr];

			// lis가 될 수 있는 위치정보를 first에 담고
			// 실제 그 값을 second에 담아준다.
			ans[pArr].first = pLis;
			ans[pArr].second = arr[pArr];
		}

		else
		{
			int pos = _lower_bound(0, pLis, arr[pArr]);
			lis[pos - 1] = arr[pArr];

			// lis가 될 수 있는 위치정보를 first에 담고
			// 실제 그 값을 second에 담아준다.
			ans[pArr].first = pos - 1;
			ans[pArr].second = arr[pArr];
		}

		pArr++;
	}

	printf("%d\n", pLis + 1);

	/*
		실제 lis 배열을 구하는 알고리즘을 보자
		예를들면 다음과 같다.

		1 6 2 5 7 3 5 6인 경우
		ans배열에는 다음과 같이 들어간다.

		first ::  0 1 1 2 3 2 3 4
		second :: 1 6 2 5 7 3 5 6

		이 값을 first를 기준으로 뒤에서 부터 조사해오면
		first가 4일때 (6) - > first가 3일때 (5) -> first가 2일때 (3)
		-> first가 1일때 (2) -> first가 0일때(1)이다.
		이것을 스택에 담아 역출력하면 1,2,3,5,6이라는 실제 배열을 구할 수 있다.
	*/

	int t = pLis;

	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i].first == t)
		{
			s.push(ans[i].second);
			t--;
		}
	}

	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}