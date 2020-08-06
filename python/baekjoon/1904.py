N = int(input())

x = 1
y = 2
z = 0
for i in range(3,N+1):
    z = (x+y)%15746
    x = y
    y = z

if N==1:
    print(1)
elif N==2:
    print(2)
else:
    print(z%15746)