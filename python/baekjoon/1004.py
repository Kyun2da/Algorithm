# 출발지와 도착지 둘다 한 원에 포함될 때  -> 이 경우 원을 지날필요 없음
# 출발지는 포함, 도착지는 포함 안될 때 -> +1을해준다.
# 출발지 포함 안되고, 도착지는 포함될 때 -> +1을 해준다.
# 출발지 도착지 둘다 포함 안될 때 -> 원을 지날필요 없음
import sys
import math


def isInclude(x1, y1, cx, cy, r):
    if r >= math.sqrt((x1 - cx) ** 2 + (y1 - cy) ** 2):
        return True
    return False


t = int(sys.stdin.readline())

for _ in range(t):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    ans = 0
    for _ in range(n):
        cx, cy, r = map(int, sys.stdin.readline().split())
        if isInclude(x1, y1, cx, cy, r) and isInclude(x2, y2, cx, cy, r):
            continue
        elif isInclude(x1, y1, cx, cy, r):
            ans += 1
        elif isInclude(x2, y2, cx, cy, r):
            ans += 1
        else:
            continue
    print(ans)
