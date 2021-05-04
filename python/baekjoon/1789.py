n = int(input())

num = 0
while True:
    if num * (num + 1) <= n * 2:
        num += 1
    else:
        break

print(num - 1)
