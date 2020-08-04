#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
	
	cout << "upper_bound(6) : " << upper_bound(arr, arr+10, 6) - arr + 1 << endl;
	cout << "upper_bound(7) : " << upper_bound(arr, arr + 10, 7) - arr + 1 << endl;
	cout << "upper_bound(8) : " << upper_bound(arr, arr + 10, 8) - arr + 1 << endl;
	cout << "upper_bound(9) : " << upper_bound(arr, arr + 10, 9) - arr + 1 << endl;
	return 0;
}