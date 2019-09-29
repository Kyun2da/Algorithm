#include <cstdio>
#include <stdlib.h>
//버블 정렬 ( O(n^2)을 만족한다)
//거의 모든 상황에서 최악의 상황을 보여준다.
//하지만 이미 정렬된 자료에서는 한번만 돌면 되기 때문에 최선의 성능을 보여준다

void Bubble_Sort(int a[], int len) //ex. 54321 을 12345로 오름차순정렬 , 맨 뒤부터 큰수대로 정렬된다
{
	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int num;
	int* arr;
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	Bubble_Sort(arr, num);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}