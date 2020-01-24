#include <iostream>

using namespace std;
int A[100][100], B[100][100], arr[100][100];

int main()
{
	int N, M, K, sum;
	

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			sum = 0;
			for (int h = 0; h < M; h++)
			{
				sum += A[i][h] * B[h][j];
			}
			arr[i][j] = sum;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout <<endl;
	}
	return 0;
}