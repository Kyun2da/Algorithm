str = input()
arr =  [-1 for i in range(26)]
for i in range(len(str)):
    idx = ord(str[i])-97
    if arr[idx]== -1:
        arr[idx] = i

for i in arr:
    print(i, end=" ")