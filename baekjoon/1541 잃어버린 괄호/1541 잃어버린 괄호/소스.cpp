#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int sum = 0, num = 0;
	bool minus_flag = false;

	cin >> s;
	//���� ó���� ������ ���ڴ� ���ڶ�� ���������� ������ �� ����
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10;
			num += s[i] - '0';
		}
		else if (s[i] == '-')
		{
			if (minus_flag == true)
				sum -= num;
			else
				sum += num;
			num = 0;
			minus_flag = true;
		}
		else // + �� ���
		{
			if (minus_flag == true)
				sum -= num;
			else
				sum += num;
			num = 0;
		}
	}

	if (minus_flag == true)
		sum -= num;
	else
		sum += num;

	cout << sum << endl;
	return 0;
}