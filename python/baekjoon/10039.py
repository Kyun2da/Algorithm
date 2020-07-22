sum=0
for i in range(5):
    a = int(input())
    if a<40:
        sum+=40
    else:
        sum+= a

print(sum//5)