n = int(input())

for i in range(1, n + 1):
    for j in range(n - i):
        print(end=" ")
    print("*" * (2 * i - 1), end="")
    print()
for i in range(1, n):
    for j in range(i):
        print(" ", end="")
    print("*" * (2 * n - 2 * i - 1), end="")
    print()
