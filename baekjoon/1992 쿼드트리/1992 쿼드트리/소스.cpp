#include <iostream>
#include <string>

using namespace std;
int arr[65][65];

void divide_conquer(int st_x, int st_y, int ed_x, int ed_y)
{
	int check = arr[st_x][st_y];
	if (st_x == ed_x && st_y == ed_y)
	{
		cout << check;
		return;
	}
	
	for (int i = st_x; i < ed_x; i++)
	{
		for (int j = st_y; j < ed_y; j++)
		{
			if (check != arr[i][j])
				check = 2;
			if (check == 2)
			{
				cout << "(";
				divide_conquer(st_x, st_y, (st_x+ed_x)/2, (st_y+ed_y)/2);
				divide_conquer(st_x, (st_y + ed_y) / 2, (st_x + ed_x) / 2, ed_y);
				divide_conquer((st_x+ed_x)/2, st_y, ed_x, (st_y+ed_y)/2);
				divide_conquer((st_x + ed_x) / 2, (st_y + ed_y) / 2, ed_x, ed_y);
				cout << ")";
				return;
			}
		}
	}

	if (check == 0)
		cout << 0;
	else
		cout << 1;
	
	return;
}

int main()
{
	int N;
	string s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = s[j]-'0';
		}
	}

	divide_conquer(0, 0, N, N);

	return 0;
}