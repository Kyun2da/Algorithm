x = int(input())

count = 0

while x > 0:
    x -= count
    count += 1

x = count + x - 1

anw = str(x) + '/' + str(count - x)
if count % 2 == 0:
    anw = str(count - x) + '/' + str(x)
print(anw)