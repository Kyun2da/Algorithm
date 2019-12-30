#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	int t_case, N, M, important, ans;
	pair <int, int> tmp;
	cin >> t_case;
	queue <pair<int, int>> q;  // index�� �߿䵵
	priority_queue <int> pq;
	for (int i = 0; i < t_case; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> important;
			q.push(pair<int,int>(j, important));
			pq.push(important);
		}
		ans = 1; //��� ������ �ʱⰪ 1�� ����
		while (1)
		{
			if (q.front().second == pq.top()) //�켱���� ť�� �߿䵵�� ť�� ������ ������ �߿䵵�� ���ٸ� ���
			{
				if (q.front().first == M) //ã�����ϴ� �����ͼ����� ������� ������ ����ϰ� break
				{
					cout << ans << "\n";
					break;
				}
				q.pop();
				pq.pop();
				ans++;
			}
			else
			{
				tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}
		//���� �۾��� �����ϱ� ���� ť�� �켱���� ť�� �� ����ش�
		while (!q.empty())  
			q.pop();
		while (!pq.empty())
			pq.pop();
	}
	return 0;
}