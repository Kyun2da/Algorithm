import sys
from collections import deque

input = sys.stdin.readline

n, l, r = map(int, input().split())

arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


# bfs로 동맹인 나라 탐색
def bfs(i, j):
    global populationSum, flag
    q = deque()
    q.append([i, j])
    while q:
        x, y = q.popleft()
        populationSum += arr[x][y]
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            # 배열안에 nx, ny가 있고, 아직 방문하지 않았으며, 두 나라의 인구 차이가 l<=x<=r 일때 국경을 연다.
            if 0 <= nx < n and 0 <= ny < n and not vis[nx][ny] and l <= abs(arr[x][y] - arr[nx][ny]) <= r:
                vis[nx][ny] = True
                q.append([nx, ny])
                tmp.append([nx, ny])
                flag = True


ans = 0  # 답 출력 변수
while True:  # 더이상 인구이동이 없을때까지 한다.
    # print(arr)
    flag = False  # 국경선이 열리는지 탐지하는 플래그
    vis = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not vis[i][j]:
                tmp = []  # 연합 위치가 담길 배열
                populationSum = 0  # 연합 총 인구 수
                tmp.append([i, j])
                vis[i][j] = True
                bfs(i, j)
                length = len(tmp)
                for k in range(length):  # 연합의 인구수를 평균으로 나눠줌
                    sx, sy = tmp[k]
                    arr[sx][sy] = populationSum // length
    if not flag:
        break
    ans += 1
print(ans)
