from bisect import bisect_left, bisect_right

N = int(input())
A = list(map(int,input().split()))
M = int(input())
B = list(map(int,input().split()))

A.sort()
for x in B:
    if bisect_right(A,x)-bisect_left(A,x) == 0:
        print(0)
    else:
        print(1)