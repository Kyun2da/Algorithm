num = int(input())

for i in range(num):
    print(" "*(num-1-i), end="")
    print("*"*(i+1))