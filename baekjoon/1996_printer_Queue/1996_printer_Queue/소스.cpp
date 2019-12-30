#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	int t_case, N, M, important, ans;
	pair <int, int> tmp;
	cin >> t_case;
	queue <pair<int, int>> q;  // index와 중요도
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
		ans = 1; //출력 순서의 초기값 1로 해줌
		while (1)
		{
			if (q.front().second == pq.top()) //우선순위 큐의 중요도와 큐의 빼려는 원소의 중요도가 같다면 출력
			{
				if (q.front().first == M) //찾고자하는 프린터순서가 출력됬으면 순서를 출력하고 break
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
		//다음 작업을 수행하기 위해 큐와 우선순위 큐를 싹 비워준다
		while (!q.empty())  
			q.pop();
		while (!pq.empty())
			pq.pop();
	}
	return 0;
}