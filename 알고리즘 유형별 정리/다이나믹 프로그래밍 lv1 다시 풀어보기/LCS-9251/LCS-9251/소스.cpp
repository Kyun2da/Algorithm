//LCS 알고리즘
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	for (int i = 0; i <= 1000; i++) arr[0][i] = 0, arr[i][0] = 0;
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])
				arr[i][j] = arr[i-1][j-1]+1;
			else
				arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
		}
	}

	cout << arr[s1.length()][s2.length()] << endl;

	return 0;
}