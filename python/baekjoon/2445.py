n = int(input())

for i in range(1, n + 1):
    print("*" * i, end="")
    print(" " * (n * 2 - i * 2), end="")
    print("*" * i, end="")
    print()
for i in range(n - 1, -1, -1):
    print("*" * i, end="")
    print(" " * (n * 2 - i * 2), end="")
    print("*" * i, end="")
    print()