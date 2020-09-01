n, k = map(int, input().split())

arr = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr.sort()
arr2.sort(reverse=True)

for i in range(k):
    if arr[i] < arr2[i]:
        arr[i], arr2[i] = arr2[i], arr[i]
    else:
        break

print(sum(arr))