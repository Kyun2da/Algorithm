#include <iostream>

using namespace std;

int arr[2187][2187];
int minus_one_num=0;
int zero_num=0;
int one_num=0;

void divide_conquer(int x, int y, int len)
{
	int check = arr[x][y];
	if (len==1)
	{
		if (check == -1)
			minus_one_num++;
		else if (check == 0)
			zero_num++;
		else
			one_num++;
		return;
	}

	for (int i = x; i < x+len; i++)
	{
		for (int j = y; j < y+len; j++)
		{
			if (check != arr[i][j])
			{
				len = len / 3;
				divide_conquer(x, y, len);
				divide_conquer(x+len, y, len);
				divide_conquer(x+len*2, y, len);
				divide_conquer(x, y+len, len);
				divide_conquer(x+len, y+len, len);
				divide_conquer(x+len*2, y+len, len);
				divide_conquer(x, y+len*2,len);
				divide_conquer(x+len, y+len*2,len);
				divide_conquer(x+len*2, y+len*2, len);
				return;
			}
		}
	}

	if (check == -1)
		minus_one_num++;
	else if (check == 0)
		zero_num++;
	else
		one_num++;
	return;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	divide_conquer(0, 0, N);

	cout << minus_one_num << endl;
	cout << zero_num << endl;
	cout << one_num << endl;

	return 0;
}