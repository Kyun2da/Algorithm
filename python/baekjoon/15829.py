n = int(input())

str = input()

num = 0
for i in range(len(str)):
    num += (ord(str[i]) - ord('a') + 1) * (31 ** i)

print(num % 1234567891)
