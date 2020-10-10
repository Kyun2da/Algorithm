from collections import deque

n, k = map(int, input().split())
ans = []

arr = deque([i for i in range(1, n + 1)])

while arr:
    for i in range(k - 1):
        a = arr.popleft()
        arr.append(a)
    b = arr.popleft()
    ans.append(b)

print('<', end="")
for x in ans:
    print(x, end="")
    if x != ans[-1]:
        print(", ", end="")
print(">")
