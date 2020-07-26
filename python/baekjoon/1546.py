num = int(input())

arr = list(map(int,input().split()))
res = sum(arr)/max(arr)* 100 / num
print(res)