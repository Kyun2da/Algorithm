from collections import deque
from itertools import permutations
import copy

a, b, c = map(int, input().split())
t = list(permutations([0, 1, 2], 2))

vis = []
ans = []
size = [a, b, c]
q = deque()
q.append([0, 0, c])
vis.append([0, 0, c])

while q:
    x = q.popleft()
    if x[0] == 0:
        ans.append(x[2])
    for i in range(len(t)):
        wfrom = t[i][0]
        wto = t[i][1]
        wk = copy.deepcopy(x)
        # from에서 to로가는게 물이 넘칠 때
        if x[wfrom] + x[wto] > size[wto]:
            wk[wfrom] = x[wfrom] + x[wto] - size[wto]
            wk[wto] = size[wto]
        # 물이 넘치지 않을때
        else:
            wk[wfrom] = 0
            wk[wto] = x[wfrom] + x[wto]
        if wk not in vis:
            vis.append(wk)
            q.append(wk)

print(' '.join(map(str, sorted(ans))))
