#include <cstdio>
#include <stdlib.h>
// �պ������� O(nlogn)�� �ð� ���⵵�� ������ �ִ�.
// �Ϲ����� ������� �� ������ �������� ����� ���ϸ� �������� �˰����� �ϳ��̴�.
// �����̸��� 1945�⿡ ����

/*
�պ������� ���ۿ���:
1. ����Ʈ�� ���̰� 1�����̸� �̹� ���ĵ� ������ ����.
2. ����(divide) : ���ĵ��� ���� ����Ʈ�� �������� �߶� ����� ũ���� �� �κ����� ������.
3. ����(conquer) : �� �κ� ����Ʈ�� ��������� �պ� ������ �̿��� �����Ѵ�.
4. ����(combine) : �� �κ� ����Ʈ�� �ٽ� �ϳ��� ���ĵ� ����Ʈ�� �պ��Ѵ�. �̶� ���� ����� �ӽù迭�� ����ȴ�.
5. ����(copy) : �ӽ� �迭�� ����� ����� ���� �迭�� �����Ѵ�.
*/

int arr[1000001];
int* arr2;

void merge(int left, int right) //�ΰ��� �迭 (left~mid) , (mid+1~right)�� ���� ��ĭ�����Ͽ� arr2�� �ɷ�����. �ɷ��� �迭�� �ڸ����� ����
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];
	
	for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		//2. ����
		mid = (left + right) / 2;

		//3. ����
		partition(left, mid);
		partition(mid + 1, right);
		//4. ����
		merge(left, right);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	arr2 = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	partition(0, num - 1);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}


