n = int(input())
m = int(input())

arr = []

num = 1
while True:
    if n <= num * num <= m:
        arr.append(num * num)
    elif num * num > m:
        break
    num += 1

if len(arr) == 0:
    print(-1)
else:
    print(sum(arr))
    print(arr[0])
