#include <iostream>

using namespace std;
int arr[129][129];
int white = 0, blue = 0;

void divide_conquer(int st_x, int st_y, int ed_x, int ed_y)
{
	int check = arr[st_x][st_y];
	for (int i = st_x; i < ed_x; i++)
	{
		for (int j = st_y; j < ed_y; j++)
		{
			if (check != arr[i][j])
				check = 2;
			if (check == 2)
			{
				divide_conquer(st_x, st_y, (st_x + ed_x) / 2, (st_y + ed_y) / 2); 
				divide_conquer((st_x + ed_x) / 2, st_y, ed_x , (st_y + ed_y) / 2); 
				divide_conquer(st_x, (st_y + ed_y) / 2, (st_x + ed_x) / 2, ed_y);  
				divide_conquer((st_x + ed_x) / 2, (st_y + ed_y) / 2, ed_x , ed_y); 
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;

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

	divide_conquer(0,0, N, N);
	cout << white << endl << blue << endl;

	return 0;
}