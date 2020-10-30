stick = 64
x = int(input())
ans = 0

while x != 0:
    if stick > x:
        stick //= 2
        if stick < x:
            x -= stick
            ans += 1
    elif stick == x:
        ans += 1
        x -= stick
        print(ans)
