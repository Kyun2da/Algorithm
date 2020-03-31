#include <iostream>
#include <stack>

using namespace std;

int arr[1001];
int lis[1001];
pair<int, int> ans[1001]; // first :: lis�� �� �� �ִ� ��ġ, second :: �ش��ϴ� ��
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
	int n;  //���� n�� ũ��
	cin >> n;

	for (int i = 0; i < n; i++) //������ �迭
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

			// lis�� �� �� �ִ� ��ġ������ first�� ���
			// ���� �� ���� second�� ����ش�.
			ans[pArr].first = pLis;
			ans[pArr].second = arr[pArr];
		}

		else
		{
			int pos = _lower_bound(0, pLis, arr[pArr]);
			lis[pos - 1] = arr[pArr];

			// lis�� �� �� �ִ� ��ġ������ first�� ���
			// ���� �� ���� second�� ����ش�.
			ans[pArr].first = pos - 1;
			ans[pArr].second = arr[pArr];
		}

		pArr++;
	}

	printf("%d\n", pLis + 1);

	/*
		���� lis �迭�� ���ϴ� �˰����� ����
		������� ������ ����.

		1 6 2 5 7 3 5 6�� ���
		ans�迭���� ������ ���� ����.

		first ::  0 1 1 2 3 2 3 4
		second :: 1 6 2 5 7 3 5 6

		�� ���� first�� �������� �ڿ��� ���� �����ؿ���
		first�� 4�϶� (6) - > first�� 3�϶� (5) -> first�� 2�϶� (3)
		-> first�� 1�϶� (2) -> first�� 0�϶�(1)�̴�.
		�̰��� ���ÿ� ��� ������ϸ� 1,2,3,5,6�̶�� ���� �迭�� ���� �� �ִ�.
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