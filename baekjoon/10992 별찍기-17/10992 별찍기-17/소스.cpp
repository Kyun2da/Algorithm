#include <iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	for (int k = 0; k < num - 1; k++)
	{
		for (int i = num - 1; i > k; i--)
			cout << " ";
		for (int j = 0; j < k + 1; j++)
		{
			if ((j == 0) || (j == k))
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}
	for (int m = 0; m < num * 2 - 1; m++)
		cout << "*";
	cout << "\n";
	return 0;
}