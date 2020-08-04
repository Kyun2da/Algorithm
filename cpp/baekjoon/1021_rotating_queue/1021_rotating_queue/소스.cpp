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

	for (int i = 1; i <= N; i++) //덱 마련해놓음
		dq.push_back(i);

	for (int i = 0; i < M; i++) //큐에 뽑을 순서 넣어 놓음
	{
		cin >> num;
		q.push(num);
	}
	//크기가 홀수일때 사이즈보다 작거나 같으면 왼쪽에서 뽑는게 낫고 사이즈보다 크거나 같으면 오른쪽에서 뽑는게 낫다
	//크기가 짝수일때 사이즈보다 작으면 왼쪽에서 뽑는게 낫고 사이즈보다 크거나 같으면 오른쪽에서 뽑는게 낫다
	while (!q.empty())
	{
		idx = 0;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == q.front()) //찾고자하는 원소의 인덱스를 찾는다
			{
				idx = i;
				break;
			}
		}
		//왼쪽에서 뽑을땐 q와 dq가 일치할때 빼는건 횟수에 더해주면 안됨 1번에 해당하기 떄문에 그래서 ans이 맨밑에 온다
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
		//반면 오른쪽에서 빼는건 더해줘야하므로 ans이 맨 위에 온다
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