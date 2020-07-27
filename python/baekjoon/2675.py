num = int(input())

for i in range(num):
    repeat ,str = input().split()
    repeat = int(repeat)
    for j in range(len(str)):
        print(str[j]*repeat,end="")
    print()