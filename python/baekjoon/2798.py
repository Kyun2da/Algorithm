N,M = map(int,input().split())

arr = list(map(int,input().split()))

minNum = float('Inf')
ans = 0

for i in range(0,N-2):
    for j in range(i+1,N-1):
        for k in range(j+1,N):
            temp = arr[i]+arr[j]+arr[k]
            if (M-temp) >= 0 and M-temp < minNum:
                ans = temp
                minNum = M-temp

print(ans)