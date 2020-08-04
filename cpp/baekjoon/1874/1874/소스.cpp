#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int arr[100001]; //수열이 저장될 배열
	char arr2[200002]; // push와 pop연산이 저장될 배열
	int N, i = 0, idx = 0, idx2 = 0, flag = 0;
	stack <int> s;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	i = 1;
	while (idx < N) //수열의 끝까지 다 검사할때까지
	{
		if (s.empty()) //스택이 비어있으면 푸시
		{
			s.push(i);
			arr2[idx2++] = '+';
			i++;
		}
		else if (s.top() < arr[idx]) //스택의 꼭대기가 arr[idx]보다 작으면 계속 푸시
		{
			s.push(i);
			arr2[idx2++] = '+';
			i++;
		}
		else if (s.top() == arr[idx]) //스택의 꼭대기가 arr[idx]와 같으면 pop
		{
			s.pop();
			arr2[idx2++] = '-';
			idx++;
		}
		else //스택의 꼭대기가 arr[idx]보다 크면 불가능
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