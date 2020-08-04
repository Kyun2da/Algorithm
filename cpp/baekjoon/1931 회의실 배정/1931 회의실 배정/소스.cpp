#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
pair <int, int> arr[100001];

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	int N, sum=0, end_time=0;
	

	cin >> N;
	for(int i=1; i<=N; i++) //
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr + 1, arr + N + 1, compare);
	
	for (int i=1; i<=N; i++)
	{
		if (end_time <= arr[i].first) //������ ������ �ð����� �����ϴ½ð��� �ڿ������� ä��
		{
			end_time = arr[i].second;
			sum++;
		}
	}

	cout << sum << endl;
	return 0;
}