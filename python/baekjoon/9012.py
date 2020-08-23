import sys

def isVPS(str):
    arr = []
    for i in str:
        if i=='(':
            arr.append('(')
        else:
            if len(arr)==0:
                return False
            arr.pop()
    if len(arr)==0:
        return True
    return False

N = int(input())

for _ in range(N):
    str = sys.stdin.readline().rstrip()
    if isVPS(str):
        print("YES")
    else:
        print("NO")