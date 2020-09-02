# permutation활용 but 메모리 초과
# from itertools import permutations
#
# n = int(input())
# arr = list(map(int, input().split()))
#
# tmp = list(permutations(sorted(arr), n))
#
# idx = tmp.index(tuple(arr))
# if idx == len(tmp):
#     print(-1)
# else:
#     for x in tmp[idx + 1]:
#         print(x, end=" ")

def nextPermutations(a):
    idx = len(a) - 1
    # 다음 순열이 있는지 검사
    while idx > 0 and a[idx - 1] >= a[idx]:
        idx -= 1
    if idx <= 0:
        return False

    # 다음순열을 찾는다.
    j = len(a) - 1
    while a[idx - 1] >= a[j]:
        j -= 1
    a[idx - 1], a[j] = a[j], a[idx - 1]

    j = len(a) - 1
    while idx < j:
        a[idx], a[j] = a[j], a[idx]
        idx += 1
        j -= 1

    return True


n = int(input())
arr = list(map(int, input().split()))

if nextPermutations(arr):
    print(' '.join(map(str, arr)))
else:
    print(-1)
