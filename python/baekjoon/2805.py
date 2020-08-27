import sys
N, M = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

# 절단기의 높이 최댓값과 최솟값
maxNum = max(arr)
minNum = 1
while minNum <= maxNum:
    tmp = (maxNum + minNum) // 2
    res = 0
    for x in arr:
        if x>=tmp:
            res += x - tmp
    # 가져갈 수 있는 나무의 길이가 더 많거나 같을때 : 절단기의 높이가 너무 낮음 절단기의 높이를 높여도되는가
    if res >= M:
        minNum = tmp + 1
    # 가져갈 수 있는 나무의 길이가 더 많거나 같을때 : 절단기의 높이가 너무 높음 절단기의 높이를 줄여도되는가
    else:
        maxNum = tmp - 1

print(maxNum)
