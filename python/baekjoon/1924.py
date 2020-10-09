dom = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']

month, date = map(int, input().split())
ans = date
for i in range(month):
    ans += dom[i]

print(day[ans % 7])
