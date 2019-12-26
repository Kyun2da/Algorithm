#include <iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	
		for (int k = 0; k < num; k++)
		{
			for (int i = num-1; i > k; i--)
				cout<<" ";
			for (int j = 0; j < k + 1; j++)
				cout<<"* ";
			cout<<"\n";
		}
	return 0;
}