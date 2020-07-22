num = int(input())*2

for i in range(num-1,0,-2):
    print(" "*((num-i-1)//2)+"*"*i)
for i in  range(3,num,2):
    print(" "*((num-i-1)//2)+"*"*i)