N, K = map(int,input().split())
arr = []
for _ in range(N):
    arr.append(int(input()))

maxNum = max(arr)
minNum = 1
ans = 0
while minNum<=maxNum:
    tmp = (maxNum+minNum)//2
    res = 0
    for x in arr:
        res+=x//tmp
    # 잘라낸 개수가 기준보다 적을때
    if res < K :
        maxNum = tmp-1
    # 잘라낸 개수가 기준보다 크거나 같을때
    else:
        ans = tmp
        minNum = tmp+1

print(ans)