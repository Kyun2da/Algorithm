#include <iostream>
using namespace std;
int main()
{
	int num,x,y, distance;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		int k = 0;
		int problem = y - x;
		while (pow(k, 2) < problem)
		{
			k++;
		}
		
		//cout << k << endl;
		int dab = 0;
		if (pow(k, 2) == problem) // k제곱과 똑같으면 출력한다
			dab=2 * k - 1;
		else //k보다 작으면 
		{
			dab = 2*(k-1)-1+(problem - pow(k - 1, 2)) / (k-1);
			int solve = problem - pow(k - 1, 2);
			if (solve % (k-1) != 0)
				dab+=1;
		}
		cout << dab << endl;
	}
	

	return 0;
}