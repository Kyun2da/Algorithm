#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
int arr[500000];
int count_num[8001];
using namespace std;

bool compare(int a, int b)
{
	return a < b; //�̷��� �ϸ� �������� a>b�� �ϸ� ��������
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
		count_num[arr[i] + 4000] += 1; //-4000�� 0�̵ǰ� 0�� 4000 1���ʹ� 4001~
	}
	sort(arr, arr + num, compare); //���� ���� ���� ���,�⺻������ �������� ����
	max = count_num[0];

	//�ֺ� ���ϱ�
	for (int j = 0; j <= 8000; j++)
	{
		if (max < count_num[j])
		{
			max = count_num[j];
			many_num = j - 4000;
		}
	}

	//���� �ֺ��� �������� �ι�°�� �������� �ֺ����� �Ѵ�.
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
	//������,�߾Ӱ�,�ֺ�(�������Ͻ� �ֺ��� �ι�°�� ������), ����
	printf("%.0lf\n", sum / double(num)); //��� ���
	printf("%d\n", arr[num / 2]); //�߾� ��
	printf("%d\n", many_num);
	printf("%d\n", arr[num - 1] - arr[0]);
	return 0;
}