import sys
from collections import Counter

N = int(sys.stdin.readline())

arr = []
for i in range(N):
    K = int(sys.stdin.readline())
    arr.append(K)

arr.sort()

mod = 0
modes = Counter(arr).most_common()
print(modes)
if N > 1:
    if modes[0][1] == modes[1][1]:
        mod = modes[1][0]
    else:
        mod = modes[0][0]
else:
    mod = modes[0][0]
print(round(sum(arr)/N))
print(arr[N//2])
print(mod)
print(arr[N-1]-arr[0])