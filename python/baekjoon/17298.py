import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
stack = []
ans = [-1] * n

for i, x in enumerate(arr):
    while stack and stack[-1][1] < x:
        ans[stack[-1][0]] = x
        stack.pop()

    stack.append([i, x])

print(' '.join(map(str, ans)))
