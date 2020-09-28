# 방법론 N만큼의 길이의 배열의 부분집합을 구하는 것은 엄청난 시간복잡도를 유발한다.
# 따라서 N//2로 나눠서 각각의 합을 배열에 저장하고, 투포인터를 사용하여 답을 구한다.
# 다만, 주의해야할 점은 s가 0일경우 공집합으로 답이 하나 더생기기 때문에 하나를 빼주어야 답이된다.

from itertools import combinations

n, s = map(int, input().split())

arr = list(map(int, input().split()))

left, right = arr[:n // 2], arr[n // 2:]

lsum, rsum = [], []

for i in range(n // 2 + 1):
    comb = list(combinations(left, i))
    for c in comb:
        lsum.append(sum(c))

for i in range(n - n // 2 + 1):
    comb = list(combinations(right, i))
    for c in comb:
        rsum.append(sum(c))

lsum.sort()
rsum.sort()

ans = 0
lenl, lenr = len(lsum), len(rsum)
start, end = 0, lenr - 1

while start < lenl and end >= 0:
    tmpSum = lsum[start] + rsum[end]

    if tmpSum == s:
        lsame = rsame = 1

        ltmp, rtmp = start, end
        start += 1
        while start < lenl and lsum[start] == lsum[ltmp]:
            lsame += 1
            start += 1
        end -= 1
        while end >= 0 and rsum[end] == rsum[rtmp]:
            rsame += 1
            end -= 1

        ans += lsame * rsame
    elif tmpSum < s:
        start += 1
    else:
        end -= 1

print(ans - 1 if s == 0 else ans)
