import sys

arr1 = set()
arr2 = set()
ans = []
n, m = map(int, sys.stdin.readline().split())

for _ in range(n):
    arr1.add(sys.stdin.readline().rstrip())

for _ in range(m):
    arr2.add(sys.stdin.readline().rstrip())

ans = arr1 & arr2
ans = list(ans)

print(len(ans))
ans.sort()
for person in ans:
    print(person)
