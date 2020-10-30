n = int(input())
arr = list(map(int, input().split()))
m = int(input())
question = list(map(int, input().split()))

arr.sort()
ans = []


# 이진 탐색(재귀)
def binarySearch(target, start, end):
    if start > end:
        return False
    mid = (start + end) // 2
    # 찾은 경우 중간점 인덱스 반환
    if arr[mid] == target:
        return True
    # 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    elif arr[mid] > target:
        return binarySearch(target, start, mid - 1)
    # 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else:
        return binarySearch(target, mid + 1, end)


for x in question:
    if binarySearch(x, 0, len(arr) - 1):
        ans.append(1)
    else:
        ans.append(0)

print(' '.join(map(str, ans)))
