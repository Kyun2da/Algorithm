// https://twinw.tistory.com/126
// lcs �˰����� Ȱ���Ѵ�.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1000][1000];

int main()
{
	
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < 1000; i++) //�Ǿ��� �迭�� 0 ���� �ʱ�ȭ
	{
		arr[i][0] = 0;
		arr[0][i] = 0;
	}

	for (int i = 1; i <= s2.size(); i++)
	{
		for (int j = 1; j <= s1.size(); j++)
		{
			if (s2[i - 1] == s1[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}

	cout << arr[s2.size()][s1.size()];
	
	

	return 0;
}