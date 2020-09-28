t = int(input())
n = int(input())
arrA = list(map(int, input().split()))
m = int(input())
arrB = list(map(int, input().split()))

lsum, rsum = [], []

for i in range(len(arrA)):
    tmp = 0
    for j in range(i, len(arrA)):
        tmp += arrA[j]
        lsum.append(tmp)

for i in range(len(arrB)):
    tmp = 0
    for j in range(i, len(arrB)):
        tmp += arrB[j]
        rsum.append(tmp)

lsum.sort()
rsum.sort()

# print(lsum)
# print(rsum)
ans = 0
lenl, lenr = len(lsum), len(rsum)
start, end = 0, lenr - 1

while start < lenl and end >= 0:
    tmpSum = lsum[start] + rsum[end]

    if tmpSum == t:
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
    elif tmpSum < t:
        start += 1
    else:
        end -= 1


print(ans)
