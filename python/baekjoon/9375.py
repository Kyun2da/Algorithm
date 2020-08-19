T = int(input())

for _ in range(T):
    N = int(input())
    items = {}
    for i in range(N):
        item, gear = input().split()
        if not gear in items:
            items[gear] = []
        items[gear].append(item)

    ans = 1
    for i in items:
        ans *= len(items[i]) + 1
    ans -= 1
    print(ans)
