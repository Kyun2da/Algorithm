#include <iostream>
using namespace std;

// DP����
// ��ƼĿ�� �밢������ �ۿ� �̵��� ������.
// ��ƼĿ�� �밢�� ��ĭ���� �̵��ϰų� �밢����ĭ���� �̵��ϰų� ���� �Ѱ����� ���̽��� �����Ѵ�.
//�̵��Ҷ����� �ִ��� �����ְ� �����ϴ� dp ��� ä��
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int a[2][100001]; //���� ���� �� �迭
int b[2][100001]; // ���� �ִ��� ����� �迭

int main()
{
	int n; //����� test?
	int width;
	cin >> n;
	a[0][0] = 0, a[1][0] = 0, b[0][0] = 0, b[1][0] = 0;  //��ĭ�� �̵��ϴ� ���� ����Ͽ� �Ǿ��� �ڸ��� 0�� �ٿ��شٰ����
	while (n--)
	{
		cin >> width;
		for(int i=0; i<2; i++)
		for (int j = 1; j <=width; j++)
		{
			cin >> a[i][j];
		}

		b[0][1] = a[0][1], b[1][1] = a[1][1];

		for (int i = 2; i <= width; i++)
		{
			b[0][i] = Max(b[1][i - 1], b[1][i - 2]) + a[0][i];
			b[1][i] = Max(b[0][i - 1], b[0][i - 2]) + a[1][i];
		}
		cout << Max(b[0][width], b[1][width]) <<endl;
	}




	return 0;
}