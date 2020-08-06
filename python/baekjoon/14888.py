def dfs(index,res):
    global minAns
    global maxAns
    if index==N-1:
        if minAns > res:
            minAns = res
        if maxAns < res:
            maxAns = res
        return res
    for i in range(4):
        temp = res
        if operator[i]==0:
            continue
        if i==0:
            res+=numArr[index+1]
        elif i==1:
            res-=numArr[index+1]
        elif i==2:
            res*=numArr[index+1]
        else:
            if res<0:
                res = abs(res)//numArr[index+1]*-1
            else:
                res //=numArr[index+1]
        operator[i] -= 1
        dfs(index+1,res)
        operator[i] += 1
        res = temp



N = int(input())
numArr = list(map(int,input().split()))
operator = list(map(int,input().split()))
minAns = float('Inf')
maxAns = float('-Inf')

dfs(0,numArr[0])
print(maxAns)
print(minAns)