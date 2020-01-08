#include <iostream>

using namespace std;

int main()
{
	long long int arr[101];
	int num, ans;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= 100; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 3];
	}

	cin >> num;
	for(int i=0; i<num; i++)
	{
		cin >> ans;
		cout << arr[ans] << endl;
	}
		
	return 0;
}