import sys

N = int(input())

count = 0
stack = []
ans = []
isStack = True

for _ in range(0, N):
    K = int(input())
    while count < K:
        count += 1
        stack.append(count)
        ans.append('+')
    if stack[-1] == K:
        stack.pop()
        ans.append('-')
    else:
        isStack = False
        break

if isStack:
    print("\n".join(ans))
else:
    print("NO")
