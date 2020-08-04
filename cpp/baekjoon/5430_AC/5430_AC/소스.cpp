#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int T, n,num=0, reverse=1,flag=0;
	deque <int> dq;
	string p,x;
	

	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		flag = 0; //error플래그 초기화
		reverse = 1; //순서 초기화
		cin >> p >> n >> x;
		for (int j = 0; j < x.size(); j++)
		{
			if (x[j] == '1' && x[j + 1] == '0' && x[j + 2] == '0')
			{
				dq.push_back(100);
				j += 2;
			}
			else if (x[j] >= '0' && x[j] <= '9')
			{
				if (x[j + 1] >= '0' && x[j + 1] <= '9')
					num = (x[j]-'0') * 10;
				else
				{
					num += (x[j]-'0');
					dq.push_back(num);
					num = 0;
				}
			}
		}

		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == 'R')
			{
				reverse *= -1; //1은 front를 처음으로 보고 -1은 back을 처음으로 본다
			}
			else
			{
				if (dq.empty())
				{
					cout << "error" << endl;
					dq.clear();
					flag = 1;
					break;
				}
				else
				{
					if (reverse == 1) //정순 front를 뺀다
					{
						dq.pop_front();
					}
					else //역순 back을 뺀다
					{
						dq.pop_back();
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "[";
			if (!dq.empty())
			{
				if (reverse == 1) //front에서 출력
				{

					while (dq.size() != 1)
					{
						cout << dq.front() << ",";
						dq.pop_front();
					}
					cout << dq.front();
					dq.pop_front();
				}
				else
				{
					while (dq.size() != 1)
					{
						cout << dq.back() << ",";
						dq.pop_back();
					}
					cout << dq.back();
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}