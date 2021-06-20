a, b = map(int, input().split())

arr = [1 for _ in range(b - a + 1)]
cnt = 0
i = 2

while i ** 2 <= b:
    tmp = i ** 2
    mul = a // tmp
    while mul * tmp <= b:
        if mul * tmp - a >= 0 and mul * tmp <= b:
            arr[mul * tmp - a] = 0
        mul += 1
    i += 1

print(sum(arr))
