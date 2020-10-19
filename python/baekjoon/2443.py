n = int(input())

for i in range(n):
    for _ in range(i):
        print(" ", end="")
    for _ in range(0, 2 * n - 2 * i - 1):
        print("*", end="")
    print()
