n = int(input())

arr = []
for _ in range(n):
    k = int(input())
    arr.append(k)

arr.sort(reverse=True)

print(arr)
