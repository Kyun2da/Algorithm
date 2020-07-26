num = int(input())

for i in range(num):
    arr = list(map(int,input().split()))
    people = arr.pop(0)
    avg = sum(arr)/people
    count = 0
    for j in range(people):
        if arr[j]>avg:
            count+=1
    print("%0.3f%%"%(count/people*100))
