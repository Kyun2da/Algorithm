#include <iostream>

using namespace std;

int main()
{
	int N,insu=2;

	cin >> N;
	while (N != 1)
	{
		if (N % insu == 0)
		{
			N /= insu;
			cout << insu << endl;
			insu = 1;
		}

		insu++;
	}


	return 0;
}