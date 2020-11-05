from itertools import combinations

n, m = map(int, input().split())
arr = []
ans = 10e9
for _ in range(n):
    arr.append(list(map(int, input().split())))

house = []
chickenHouse = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            house.append([i, j])
        elif arr[i][j] == 2:
            chickenHouse.append([i, j])

#print(house)
#print(chickenHouse)
#print(list(combinations(chickenHouse, m)))
comblist = list(combinations(chickenHouse, m))

# 치킨집의 리스트를 돌면서
for i in range(len(comblist)):
    # 집과 가장가까운 치킨집을 찾아 거리를 구한다.
    tmp = [1000] * len(house)
    for j in range(m):
        x, y = comblist[i][j]
        for k in range(len(house)):
            tmp[k] = min(tmp[k], abs(x - house[k][0]) + abs(y - house[k][1]))
    ans = min(ans, sum(tmp))

print(ans)