#include <iostream>
using namespace std;

// DP문제
// 스티커는 대각선으로 밖에 이동할 수없다.
// 스티커는 대각선 두칸으로 이동하거나 대각선한칸으로 이동하거나 둘중 한가지의 케이스만 존재한다.
//이동할때마다 최댓값을 구해주고 저장하는 dp 방식 채택
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int a[2][100001]; //원래 값이 들어갈 배열
int b[2][100001]; // 값의 최댓값이 저장될 배열

int main()
{
	int n; //몇번의 test?
	int width;
	cin >> n;
	a[0][0] = 0, a[1][0] = 0, b[0][0] = 0, b[1][0] = 0;  //두칸씩 이동하는 것을 고려하여 맨앞의 자리를 0을 붙여준다고생각
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