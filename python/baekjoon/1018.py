N,M = map(int,input().split())

arrBlack = []
arrWhite = []
arr = []
min_cnt = 64

for i in range(8):
    if i % 2 == 0:
        arrBlack.append(list(['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']))
        arrWhite.append(list(['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']))
    else:
        arrWhite.append(list(['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']))
        arrBlack.append(list(['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']))

for i in range(N):
    str = list(input())
    arr.append(str)

for i in range(N - 7):
    for j in range(M - 7):
        w_cnt = 0
        b_cnt = 0
        # b로 시작하는 체스판과 비교하여 cnt 세기
        for k in range(i, i + 8):
            for s in range(j, j + 8):
                if arrBlack[k-i][s-j] != arr[k][s]:
                    b_cnt += 1
        # w로 시작하는 체스판과 비교하여 cnt세기
        for k in range(i, i + 8):
            for s in range(j, j + 8):
                if arrWhite[k-i][s-j] != arr[k][s]:
                    w_cnt += 1
        min_cnt = min(min_cnt, min(b_cnt, w_cnt))
print(min_cnt)