from bisect import bisect_left, bisect_right

N = int(input())
arr1 = list(map(int,input().split()))
M = int(input())
arr2 = list(map(int,input().split()))

arr1.sort()

for x in arr2:
    print(bisect_right(arr1,x)-bisect_left(arr1,x), end=" ")