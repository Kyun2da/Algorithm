import sys

input = sys.stdin.readline

n, k = map(int, input().split())

vis = [False for _ in range(0, n + 1)]

num = 0
flag = False
for i in range(2, n+1):
    mul = 1
    tmp = i
    while tmp <= n:
        if not vis[tmp]:
            vis[tmp] = True
            num += 1
            # print(tmp, num)
        if num == k:
            print(tmp)
            exit()
        mul += 1
        tmp = i * mul

