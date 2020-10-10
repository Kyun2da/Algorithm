n = int(input())

arrA = list(map(int, input().split()))
arrB = list(map(int, input().split()))

arrA.sort()
arrB.sort(reverse=True)
ans = 0
for i in range(n):
    ans += arrA[i] * arrB[i]

print(ans)
