#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N, num, sum;
	map<string, int> m;
	map<string, int>::iterator iter;

	string s, dressType;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		sum = 1;
		m.clear();
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> s >> dressType;
			iter = m.find(dressType);
			if (iter == m.end()) //존재안하면
			{
				m.insert(pair<string, int>(dressType, 1));
			}
			else {
				iter->second = iter->second + 1;
			}
		}

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			sum = sum * (iter->second + 1);
		}
		sum = sum - 1;
		cout << sum << endl;
	}

	
	return 0;
}