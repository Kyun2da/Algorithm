N, K = map(int, input().split())

tmp1 = 1
tmp2 = 1

for i in range(K):
    tmp1 *= N - i

for i in range(K):
    tmp2 *= K - i

print(tmp1 // tmp2)
