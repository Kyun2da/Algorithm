import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

new_arr = list(sorted(set(arr)))
answer = []
dic = {val: idx for idx, val in enumerate(new_arr)}

for i in arr:
    print(dic[i], end=" ")
