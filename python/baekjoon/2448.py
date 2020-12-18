import sys

input = sys.stdin.readline

n = int(input())
arr = [[' '] * (2 * n - 1) for _ in range(n)]


def star(c, x, y):
    if c == 3:
        arr[y][x] = '*'
        arr[y + 1][x - 1] = '*'
        arr[y + 1][x + 1] = '*'
        arr[y + 2][x - 2] = '*'
        arr[y + 2][x - 1] = '*'
        arr[y + 2][x] = '*'
        arr[y + 2][x + 1] = '*'
        arr[y + 2][x + 2] = '*'
        return
    star(c / 2, x, y)
    star(c / 2, int(x - c / 2), int(y + c / 2))
    star(c / 2, int(x + c / 2), int(y + c / 2))


star(n, n - 1, 0)

for i in range(n):
    print(''.join(map(str, arr[i])))
