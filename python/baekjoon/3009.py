a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
d = []
if a[0]==b[0]:
    d.append(c[0])
elif b[0]==c[0]:
    d.append(a[0])
else:
    d.append(b[0])

if a[1]==b[1]:
    d.append(c[1])
elif b[1]==c[1]:
    d.append(a[1])
else:
    d.append(b[1])

print("%d %d"%(d[0],d[1]))