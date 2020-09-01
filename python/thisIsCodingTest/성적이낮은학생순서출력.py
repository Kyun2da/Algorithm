n = int(input())

arr = []
for _ in range(n):
    name, score = map(str,input().split())
    arr.append((name,int(score)))

arr.sort(key=lambda student: student[1])

for i in range(len(arr)):
    print(arr[i][0], end=' ')