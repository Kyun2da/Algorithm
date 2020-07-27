str = list(input().split())

str[0] = int(str[0][::-1])
str[1] = int(str[1][::-1])

print(max(str))
