import sys

input = sys.stdin.readline

# x는 추가한 가로선 개수, y는 후보군 개수
def solve(x, y):
    global ans
    if x >= ans:
        return
    if check():
        ans = x
        return
    for idx in range(y + 1, len(candidates)):
        i, j = candidates[idx]
        if line[i][j - 1] == 0 and line[i][j + 1] == 0:
            line[i][j] = 1
            solve(x + 1, idx)
            line[i][j] = 0


# i번 세로선의 결과가 i가 나오는지 체크
def check():
    for i in range(1, n + 1):
        now = i
        for j in range(1, h + 1):
            if line[j][now] == 1:
                now += 1
            elif line[j][now - 1] == 1:
                now -= 1
        if i != now:
            return False
    return True


n, m, h = map(int, input().split())
line = [[0] * (n + 1) for _ in range(h + 1)]
candidates = []
ans = 4

for _ in range(m):
    a, b = map(int, input().split())
    line[a][b] = 1

# 가로선을 추가할 수 있는 후보 추가
for i in range(1, h + 1):
    for j in range(1, n):
        if line[i][j] == 0 and line[i][j - 1] == 0 and line[i][j + 1] == 0:
            candidates.append([i, j])

solve(0, -1)
print(ans if ans < 4 else -1)
