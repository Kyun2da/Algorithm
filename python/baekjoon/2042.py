import sys


# 세그먼트 트리 초기화
def init(start, end, node):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)
    return tree[node]


# 구간 합 구하기
def summit(start, end, node, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]

    mid = (start + end) // 2
    return summit(start, mid, node * 2, left, right) + summit(mid + 1, end, node * 2 + 1, left, right)


# 특정 인덱스 값 변경
def update(start, end, node, index, dif):
    if index < start or index > end:
        return
    tree[node] += dif
    if start == end:
        return

    mid = (start + end) // 2
    update(start, mid, node * 2, index, dif)
    update(mid + 1, end, node * 2 + 1, index, dif)


n, m, k = map(int, sys.stdin.readline().split())
arr = []
tree = [0] * (4 * n)
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

init(0, n - 1, 1)

for _ in range(m + k):
    a, b, c = map(int, sys.stdin.readline().split())
    if a == 1:
        b -= 1
        diff = c - arr[b]
        arr[b] = c
        update(0, n - 1, 1, b, diff)
    else:
        print(summit(0, n - 1, 1, b - 1, c - 1))
