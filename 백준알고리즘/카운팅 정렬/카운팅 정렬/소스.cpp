#include <cstdio>

//Counting sort는 평균적으로 O(n)의 시간 복잡도를 갖는다.
//카운팅 정렬의 동작원리 : 
//1. 먼저 숫자가 각각 몇번 들어가는지 센다 0부터 최대수~까지  (여기서 카운팅정렬이 최대수가 몇이느냐에따라 시간복잡도가 상당히 커지거나 작아진다고 볼 수 있다.)
//2. 등장횟수를 누적합으로 바꿔준다. 이 누적합은 해당 숫자가 나올 마지막 자리라는 뜻이다.
//3. 배열을 한번더 돌며 해당배열에 누적합에 해당하는 인덱스에 가서 숫자를 넣고 다음 나올 똑같은 수를 위해 누적합을 -1해준다

#define MAX_NUM 10000
int arr[10001];
int main()
{
	int n, i;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}


	return 0;
}
