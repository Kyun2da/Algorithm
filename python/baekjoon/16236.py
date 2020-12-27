import sys
from collections import deque

input = sys.stdin.readline

arr = []
sharkSize = 2
canEatArr = []
q = deque()
needFish = 2
answer = 0
time = 0
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

n = int(input())
vis = [[False] * n for _ in range(n)]
# 맵 저장
for _ in range(n):
    arr.append(list(map(int, input().split())))

# 아기 상어 현재 위치 저장
flag = False
for i in range(n):
    for j in range(n):
        if arr[i][j] == 9:
            q.append([i, j])
            arr[i][j] = 0
            vis[i][j] = True
            flag = True
            break
    if flag:
        break

while q:
    q = deque(sorted(q))  # 위와 왼쪽을 우선시해서 가야하므로 큐를 소팅
    # print(q)
    # print(time)
    size = len(q)
    flag = False
    for _ in range(size):
        x, y = q.popleft()
        # 먹이가 있으면 먹고 그 위치를 현재 위치로 초기화
        if arr[x][y] != 0 and arr[x][y] < sharkSize:
            arr[x][y] = 0
            needFish -= 1
            q, vis = deque([[x, y]]), [[False] * n for _ in range(n)]
            vis[x][y] = True
            answer = time
            flag = True

            # 필요한 개수만큼 먹이를 다 먹었으면 상어의 크기 1 증가
            if needFish == 0:
                sharkSize += 1
                needFish = sharkSize
            break

        # 갈수있는 공간과, 그 위치에 먹이가 있는지 탐색
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 갈 수 있는 공간이고, 방문하지 않았고, 해당공간이 아기상어보다 작거나 같을때 이동 가능
            if 0 <= nx < n and 0 <= ny < n and not vis[nx][ny] and arr[nx][ny] <= sharkSize:
                q.append([nx, ny])
                vis[nx][ny] = True

    if flag:  # 먹이를 먹고 초기화하면 불필요한 시간이 한번 더 더해지므로 time+=1을 넘어가주기 위해 플래그를 넣는다.
        continue
    time += 1

print(answer)
