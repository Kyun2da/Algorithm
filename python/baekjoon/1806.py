# n, s = map(int, input().split())
#
# arr = list(map(int, input().split()))
#
# end = 0
# intervalSum = arr[0]
# ans = float('inf')
#
# for start in range(n):
#     while intervalSum < s and end < n:
#         end += 1
#         if end == n:
#             break
#         intervalSum += arr[end]
#     if intervalSum >= s:
#         # print(arr[start], arr[end])
#         ans = min(ans, end - start + 1)
#     intervalSum -= arr[start]
#
# if ans == float('inf'):
#     print(0)
# else:
#     print(ans)

# 원리는 같지만 약간 다른 풀이
n, s = map(int, input().split())
arr = list(map(int, input().split()))

sumA = [0] * (n + 1)
for i in range(1, n + 1):
    sumA[i] = sumA[i - 1] + arr[i - 1]

# 투포인터 설정
ans = float('inf')
start = 0
end = 1

while start != n:
    if sumA[end] - sumA[start] >= s:
        if end - start < ans:
            ans = end - start
        start += 1

    else:
        if end != n:
            end += 1
        else:
            start += 1

if ans == float('inf'):
    print(0)
else:
    print(ans)
