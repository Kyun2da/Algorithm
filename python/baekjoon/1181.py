N = int(input())

arr = []

for i in range(N):
    s = input()
    arr.append(s)

arr = list(set(arr))
arr.sort(key= lambda item:(len(item),item))

for item in arr:
    print(item)

