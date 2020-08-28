n = int(input())

xPos = 1
yPos = 1

arr = list(map(str, input().split()))

for pos in arr:
    if pos == 'L':
        if yPos == 1: continue
        yPos -= 1
    elif pos == 'R':
        if yPos == n: continue
        yPos += 1
    elif pos == 'U':
        if xPos == 1: continue
        xPos -= 1
    elif pos == 'D':
        if xPos == n: continue
        xPos += 1

print(xPos, yPos)
