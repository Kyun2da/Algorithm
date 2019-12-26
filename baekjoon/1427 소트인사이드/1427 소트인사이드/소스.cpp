#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int num = 0;
	int arr[10];
	int i = 0;
	scanf("%d", &num);
	while (num != 0)
	{
		arr[i] = num % 10;
		num = num / 10;
		i++;
	}
	sort(arr, arr + i, greater<int>());

	for (int j = 0; j < i; j++)
		printf("%d", arr[j]);
	return 0;
}