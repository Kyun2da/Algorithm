N = int(input())

arr = list(map(int, input().split()))
arr.sort()

ans = arr[0] * arr[-1]
print(ans)
