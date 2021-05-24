import sys

input = sys.stdin.readline

n, m = map(int, input().split())
trueP = set(map(int, input().split()[1:]))
party = []
possible = [1] * m

for _ in range(m):
    party.append(set(map(int, input().split()[1:])))

for _ in range(m):
    for i, p in enumerate(party):
        if trueP.intersection(p):
            possible[i] = 0
            trueP = trueP.union(p)

print(sum(possible))
