def postOrder(start, end):
    if start > end:
        return

    root = pre[start]
    tmp = start + 1
    for i in range(start + 1, end + 1):
        if pre[i] > root:
            tmp = i
            break

    postOrder(start + 1, tmp - 1)
    postOrder(tmp, end)
    print(pre[start])


import sys

sys.setrecursionlimit(10 ** 9)

pre = []
while True:
    try:
        num = int(input())
    except:
        break
    pre.append(num)

postOrder(0, len(pre) - 1)
