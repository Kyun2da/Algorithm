# 플로이드 워셜 알고리즘 사용

n = int(input())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

# k를 거쳐가는 경우가 있다면 갈 수 있는 경우다.
for k in range(n):
    for i in range(n):
        for j in range(n):
            if arr[i][k] and arr[k][j]:
                arr[i][j] = 1

for x in arr:
    print(' '.join(map(str, x)))
