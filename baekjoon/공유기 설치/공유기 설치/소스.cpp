#include <iostream>
#include <algorithm>

using namespace std;
long long arr[200001], ans=0, mid;
int N, C;
//�׻� mid�� �����⸦ ��ġ����
long long mybinary_search(long long st,long long ed) // ������ġ, ����ġ
{
	while (st <= ed) {
		long long router = arr[0]; //���� ������ ��ġ
		mid = (st + ed) / 2; //�ӽ� ������ �ִ� ����
		int num = 1; //���� ������ ����
		for (long long i = 1; i < N; i++)
		{
			if (arr[i] - router >= mid)
			{
				num++;
				router = arr[i];
			}
		}

		if (num >= C) //ī���õ� ������ ������ ��ġ�ϰ����ϴ� �����ⰳ������ ũ�� �Ÿ��� ��������
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