import sys

input = sys.stdin.readline

total = int(input())

for _ in range(9):
    n = int(input())
    total -= n

print(total)
