n = int(input())

remain = 1000 - n
ans = 0

ans += remain // 500
remain = remain % 500
ans += remain // 100
remain = remain % 100
ans += remain // 50
remain = remain % 50
ans += remain // 10
remain = remain % 10
ans += remain // 5
remain = remain % 5
ans += remain

print(ans)