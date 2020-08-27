N, M, K = map(int,input().split())
arr = list(map(int,input().split()))

arr.sort(reverse=True)
max1 = arr[0]
max2 = arr[1]

count = 0

# 가장 큰수가 나오는 횟수 계산
count += M // (K+1) * K   # 주기 * K번
count += M %(K+1) # 나머지도 모두 가장 큰 수 로 채운다.

result = 0
result += count * max1 + (M-count) *  max2  #가장 큰 수 + 두 번째로 큰수

print(result)