#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main()
{
	deque <int> dq;
	queue <int> q;
	int N, M, num, ans = 0, idx, tmp;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) //�� �����س���
		dq.push_back(i);

	for (int i = 0; i < M; i++) //ť�� ���� ���� �־� ����
	{
		cin >> num;
		q.push(num);
	}
	//ũ�Ⱑ Ȧ���϶� ������� �۰ų� ������ ���ʿ��� �̴°� ���� ������� ũ�ų� ������ �����ʿ��� �̴°� ����
	//ũ�Ⱑ ¦���϶� ������� ������ ���ʿ��� �̴°� ���� ������� ũ�ų� ������ �����ʿ��� �̴°� ����
	while (!q.empty())
	{
		idx = 0;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == q.front()) //ã�����ϴ� ������ �ε����� ã�´�
			{
				idx = i;
				break;
			}
		}
		//���ʿ��� ������ q�� dq�� ��ġ�Ҷ� ���°� Ƚ���� �����ָ� �ȵ� 1���� �ش��ϱ� ������ �׷��� ans�� �ǹؿ� �´�
		if ((dq.size() % 2 ==0 && idx < dq.size() / 2) || (dq.size() % 2 == 1 && idx <= dq.size() / 2)) 
		{
			while (1)
			{
				if (dq.front() == q.front())
				{
					dq.pop_front();
					q.pop();
					break;
				}
				tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				ans++;
			}
		}
		//�ݸ� �����ʿ��� ���°� ��������ϹǷ� ans�� �� ���� �´�
		else
		{
			while (1)
			{
				ans++;
				if (dq.back() == q.front())
				{
					dq.pop_back();
					q.pop();
					break;
				}
				tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}

	cout << ans << endl;



	return 0;
}