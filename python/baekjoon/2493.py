import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
stack = []
answer = [0] * n

idx = n

while len(arr) != 0:
    k = arr.pop()

    if len(stack) == 0:
        stack.append([k, idx])
    else:
        while True:
            if len(stack) != 0 and stack[-1][0] <= k:
                item, item_idx = stack.pop()
                answer[item_idx - 1] = idx
            else:
                stack.append([k, idx])
                break
    idx -= 1

for x in answer:
    print(x, end=" ")
