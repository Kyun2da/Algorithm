#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int arr[100001]; //������ ����� �迭
	char arr2[200002]; // push�� pop������ ����� �迭
	int N, i = 0, idx = 0, idx2 = 0, flag = 0;
	stack <int> s;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	i = 1;
	while (idx < N) //������ ������ �� �˻��Ҷ�����
	{
		if (s.empty()) //������ ��������� Ǫ��
		{
			s.push(i);
			arr2[idx2++] = '+';
			i++;
		}
		else if (s.top() < arr[idx]) //������ ����Ⱑ arr[idx]���� ������ ��� Ǫ��
		{
			s.push(i);
			arr2[idx2++] = '+';
			i++;
		}
		else if (s.top() == arr[idx]) //������ ����Ⱑ arr[idx]�� ������ pop
		{
			s.pop();
			arr2[idx2++] = '-';
			idx++;
		}
		else //������ ����Ⱑ arr[idx]���� ũ�� �Ұ���
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		for (int i = 0; i < idx2; i++)
			cout << arr2[i] << "\n";
	}
	else
		cout << "NO\n";

	return 0;
}