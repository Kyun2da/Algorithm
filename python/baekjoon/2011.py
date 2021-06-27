code = input()

mod = 1000000
dp = [0] * (len(code) + 1)
dp[0] = 1
dp[1] = 1

if code[0] == '0':
    print(0)
    exit()

for i in range(1, len(code)):
    tmp = code[i - 1:i + 1]
    if 10 <= int(tmp) <= 26:
        dp[i + 1] += dp[i - 1]
    if int(code[i]) > 0:
        dp[i + 1] += dp[i]

print(dp[len(code)] % mod)
