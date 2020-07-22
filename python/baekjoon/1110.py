a = int(input())
answer = a
cycle = 1
while True:
    num = a//10 + a%10
    a = (a%10)*10 + num%10
    if a == answer:
        break
    cycle+=1

print(cycle)