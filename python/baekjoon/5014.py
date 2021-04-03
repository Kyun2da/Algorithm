# f : 총 건물의 층 수
# g : 스타트링크가 있는 곳
# s : 강호가 지금 있는 곳
# u : 위로 u층을 갈 수 있음
# d : 아래로 d층을 갈 수 있음

# s 층에서 g 층으로 가기위해 눌러야하는 최소 버튼 횟수

from collections import deque

f, s, g, u, d = map(int, input().split())

q = deque([s])

vis = [False] * (f + 1)
vis[s] = True
count = 0
while q:
    for _ in range(len(q)):
        cur_pos = q.popleft()

        if cur_pos == g:
            print(count)
            exit()

        if cur_pos + u <= f and not vis[cur_pos + u]:
            q.append(cur_pos + u)
            vis[cur_pos+u] = True
        if cur_pos - d >= 1 and not vis[cur_pos - d]:
            q.append(cur_pos - d)
            vis[cur_pos - d] = True
    count += 1

print("use the stairs")
