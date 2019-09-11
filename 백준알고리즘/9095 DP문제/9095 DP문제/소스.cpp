#include <iostream>
using namespace std;

int Add[1001];
int Add_Method(int x);

int main()
{
	int Test_num;
	int num;
	cin >> Test_num;
	for (int i = 0; i < Test_num; i++)
	{
		cin >> num;
		cout << Add_Method(num)<<"\n";
	}

	return 0;
}

int Add_Method(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (Add[x] != 0) return Add[x];
	return Add[x] = Add_Method(x - 1) + Add_Method(x - 2) + Add_Method(x - 3);
}