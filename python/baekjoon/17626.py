n = int(input())

ans = 4

for i in range(int(n ** 0.5), -1, -1):
    if i * i == n:
        ans = 1
        break
    else:
        tmp = n - i * i
        for j in range(int(tmp ** 0.5), -1, -1):
            if j * j == tmp:
                ans = min(ans, 2)
                break
            else:
                tmp2 = n - i * i - j * j
                for k in range(int(tmp2 ** 0.5), -1, -1):
                    if k * k == tmp2:
                        ans = min(ans, 3)
                        break

print(ans)
