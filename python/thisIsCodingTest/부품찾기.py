def binarySearch(arr,target,start,end):
    while start<=end:
        mid = (start+end)//2
        if arr[mid]==target:
            return mid
        elif arr[mid]>target:
            end = mid -1
        else:
            start = mid +1
    return None

n = int(input())

store = list(map(int,input().split()))
m = int(input())
order = list(map(int,input().split()))

store.sort()

for item in order:
    result = binarySearch(store,item,0,n-1)
    if result != None:
        print('yes',end=" ")
    else:
        print('no',end=' ')