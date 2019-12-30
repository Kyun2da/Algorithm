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
		flag = 0; //error�÷��� �ʱ�ȭ
		reverse = 1; //���� �ʱ�ȭ
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
				reverse *= -1; //1�� front�� ó������ ���� -1�� back�� ó������ ����
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
					if (reverse == 1) //���� front�� ����
					{
						dq.pop_front();
					}
					else //���� back�� ����
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
				if (reverse == 1) //front���� ���
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