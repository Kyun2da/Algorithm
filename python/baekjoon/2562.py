arr = []
idx = 0
maxNum = 0
for i in range(9):
    num = int(input())
    if maxNum < num:
        maxNum = num
        idx =i

print(maxNum,idx+1)

'''
ans = -float('inf')
idx = -1
for i in range(1, 10):
    a = int(input())
    if a > ans:
        ans = a
        idx = i

print(ans, idx, sep='\n')
'''