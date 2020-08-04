#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int sum = 0, num = 0;
	bool minus_flag = false;

	cin >> s;
	//가장 처음과 마지막 문자는 숫자라는 전제조건이 문제에 들어가 있음
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
		else // + 일 경우
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