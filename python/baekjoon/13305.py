import sys

input = sys.stdin.readline

n = int(input())
roads = list(map(int, input().split()))
cities = list(map(int, input().split()))
min_value = 1000000001
ans = 0

for i, road in enumerate(roads):
    min_value = min(min_value, cities[i])
    ans += min_value * road

print(ans)
