def recursion(size, x, y):
    global ans
    if x == r and y == c:
        print(ans)
        exit(0)

    if size == 1:
        ans += 1
        return

    if not (x <= r < x + size and y <= c < y + size):
        ans += size * size
        return

    recursion(size // 2, x, y)
    recursion(size // 2, x, y + (size // 2))
    recursion(size // 2, x + (size // 2), y)
    recursion(size // 2, x + (size // 2), y + (size // 2))


n, r, c = map(int, input().split())
ans = 0

recursion(2 ** n, 0, 0)
