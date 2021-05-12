import sys

input = sys.stdin.readline

n, m = map(int, input().split())

dic = {}

for _ in range(n):
    name, pw = map(str, input().split())
    dic[name] = pw

for _ in range(m):
    print(dic[input().rstrip()])
