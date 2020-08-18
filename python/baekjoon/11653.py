N = int(input())

idx = 2
while N != 1:
    if N % idx == 0:
        print(idx)
        N /= idx
        idx -= 1
    idx += 1
