def bitmask():
    global maxAns
    # 비트마스크로 2^(N*M)의 경우의 수를 따져본다
    for i in range(1 << n * m):
        print(i)
        total = 0
        # 가로 합 계산
        for row in range(n):
            rowsum = 0
            for col in range(m):
                idx = row * m + col
                #가로일때
                if i & (1 << idx) != 0:
                    rowsum = rowsum * 10 + arr[row][col]
                #세로일때 앞에서나온수를 total에 더하고 rowsum 초기화
                else:
                    total += rowsum
                    rowsum = 0
            total += rowsum

        # 세로 합 계산
        for col in range(m):
            colsum = 0
            for row in range(n):
                idx = row * m + col
                if i & (1 << idx) == 0:
                    colsum = colsum * 10 + arr[row][col]
                else:
                    total += colsum
                    colsum = 0
            total += colsum
        maxAns = max(maxAns, total)


n, m = map(int, input().split())

arr = [list(map(int, input())) for _ in range(n)]

maxAns = 0
bitmask()
print(maxAns)
