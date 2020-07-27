arr = [0 for i in range(26)]
str = input().upper()
maxNum = 0
duplicate = 0
answer = ""
for i in str:
    arr[ord(i)-65]+=1

for i in range(len(arr)):
    if arr[i] > maxNum:
        duplicate = 0
        maxNum = arr[i]
        answer = i
    elif arr[i]==maxNum:
        duplicate = 1

if duplicate==1:
    print('?')
else:
    print(chr(answer+65))