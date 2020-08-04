N = int(input())

arr = []

while N!=0:
    arr.append(N%10)
    N//=10

arr.sort(reverse=True)

for item in arr:
    print(item, end="")