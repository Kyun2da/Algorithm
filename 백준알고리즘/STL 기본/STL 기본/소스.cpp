#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
int arr[500000];
int count_num[8001];
using namespace std;

bool compare(int a, int b)
{
	return a < b; //이렇게 하면 오름차순 a>b로 하면 내림차순
}

int main()
{
	int num, max, many_num;
	double sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		count_num[arr[i] + 4000] += 1; //-4000은 0이되고 0은 4000 1부터는 4001~
	}
	sort(arr, arr + num, compare); //가장 쉬운 정렬 방법,기본적으로 오름차순 정렬
	max = count_num[0];

	//최빈값 구하기
	for (int j = 0; j <= 8000; j++)
	{
		if (max < count_num[j])
		{
			max = count_num[j];
			many_num = j - 4000;
		}
	}

	//만약 최빈값이 여러개면 두번째로 작은수를 최빈값으로 한다.
	int count=0;
	for (int j = 0; j <= 8000; j++)
	{
		if (max == count_num[j])
		{
			count++;
		}
		if (count == 2)
		{
			many_num = j - 4000;
			break;
		}
	}
	//산술평균,중앙값,최빈값(여러개일시 최빈값중 두번째로 작은값), 범위
	printf("%.0lf\n", sum / double(num)); //산술 평균
	printf("%d\n", arr[num / 2]); //중앙 값
	printf("%d\n", many_num);
	printf("%d\n", arr[num - 1] - arr[0]);
	return 0;
}