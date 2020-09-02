e, s, m = map(int, input().split())

ans = 1
while True:
    if (ans % 15 == e or (ans % 15 == 0 and e == 15)) and (ans % 28 == s or (ans % 28 == 0 and s == 28)) and (
            ans % 19 == m or (ans % 19 == 0 and m == 19)):
        print(ans)
        break
    ans += 1
