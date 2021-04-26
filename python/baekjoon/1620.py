import sys

input = sys.stdin.readline

n, m = map(int, input().split())

dic = {}

for i in range(1, n + 1):
    pocketmon = input().rstrip()
    dic[pocketmon] = str(i)
    dic[str(i)] = pocketmon

for _ in range(m):
    print(dic[input().rstrip()])
