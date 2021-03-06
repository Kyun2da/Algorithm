def beforePermutation(a):

    # 이전 순열이 있는지 검사
    n = len(a) - 1
    i = n
    while i > 0 and a[i - 1] <= a[i]:
        i -= 1
    if i == 0:
        return False
    j = n
    while a[i - 1] <= a[j]:
        j -= 1
    a[i - 1], a[j] = a[j], a[i - 1]
    j = n
    while i < j:
        a[i], a[j] = a[j], a[i]
        i += 1
        j -= 1
    return True

n = int(input())
arr = list(map(int, input().split()))

if beforePermutation(arr):
    print(' '.join(map(str, arr)))
else:
    print(-1)
