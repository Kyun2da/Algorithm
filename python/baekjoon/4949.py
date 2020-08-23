import sys

def isVPS(str):
    arr = []
    for i in str:
        if i=='(':
            arr.append('(')
        elif i=='[':
            arr.append('[')
        elif i==')':
            if len(arr)==0 or arr[-1]=='[':
                return False
            else:
                arr.pop()
        elif i==']':
            if len(arr)==0 or arr[-1]=='(':
                return False
            else:
                arr.pop()
    if len(arr)==0:
        return True
    return False


while True:
    str = sys.stdin.readline().rstrip()
    if str=='.':
        break
    if isVPS(str):
        print("yes")
    else:
        print("no")