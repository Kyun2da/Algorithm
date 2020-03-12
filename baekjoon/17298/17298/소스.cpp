#include <iostream>
#include <stack>
using namespace std;
//������ ����ϸ� ��� ������ ���ʿ䰡�����Ƿ� n�������� n���� �ð����⵵�� ���ҵ�
int main()
{
	int N;
	int arr[1000001];
	int res[1000001];
	stack <int> s;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && arr[s.top()] < arr[i]) //arr[i]�� top���� Ŭ������ ��� pop�ϸ鼭 ��� �迭�� �ִ´�.
		{
			res[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) //�������� ������������ ������ -1�� �����
	{
		res[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) 
	{
		cout << res[i] << ' ';
	}
	return 0;
}