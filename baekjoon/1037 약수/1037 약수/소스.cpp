#include <iostream>

using namespace std;

int main()
{
	int N, min= 1000000, max=2, num;

	cin >> N;
	while (N--) {
		cin >> num;
		if (min > num)
			min = num;
		if (max < num)
			max = num;
	}

	cout << max * min;
	return 0;
}