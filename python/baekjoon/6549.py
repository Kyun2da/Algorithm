import sys

input = sys.stdin.readline

while True:
    n, *square = list(map(int, input().split()))
    if n == 0:
        break

    square.insert(0, 0)
    square += [0]
    check = [0]
    ans = 0

    for i in range(1, n + 2):
        while check and square[check[-1]] > square[i]:
            cur_square = check.pop()
            ans = max(ans, (i - 1 - check[-1]) * square[cur_square])
            print(ans)
        check.append(i)
    print(ans)
