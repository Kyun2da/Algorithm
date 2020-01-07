#include <iostream>

using namespace std;
int arr[1000001], num;
int main()
{
	
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= 1000000; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	cin >> num;
	printf("%d", arr[num]);


	return 0;
}