import sys

def dfs(total):
    global ans, k
    if total == k:
        ans += 1
        return
    if total + 1 <= k:
        dfs(total + 1)
    if total + 2 <= k:
        dfs(total + 2)
    if total + 3 <= k:
        dfs(total + 3)


t = int(input())
k = 0
ans = 0
for _ in range(t):
    k = int(sys.stdin.readline().rstrip())
    ans = 0
    dfs(0)
    print(ans)
