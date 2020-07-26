arr = [0 for i in range(42)]
result = 0

for i in range(10):
    num = int(input())
    arr[num%42]+=1

for i in range(42):
    if arr[i]!=0:
        result+=1

print(result)

