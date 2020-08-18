import sys


# 최대 공약수 구하기
def gcd(a, b):
    while b > 0:
        tmp = b
        b = a % b
        a = tmp
    return a


arr = []
arr2 = []

# 입력 받기
N = int(sys.stdin.readline())
for _ in range(N):
    arr.append(int(sys.stdin.readline()))

arr.sort()

# 각 수의 차를 구해서 arr2배열에 넣기
for i in range(N - 1):
    arr2.append(arr[i + 1] - arr[i])

# 모든 수의 최대 공약수를 구하기
tmp = arr2[0]
for i in arr2[1:]:
    tmp = gcd(i, tmp)

# 최대공약수의 약수를 모두 구하면 답이 된다 이때 제곱근을 활용하여 범위를 낮추도록하자
ans = []
for i in range(2, int(tmp ** 0.5) + 1):
    if tmp % i == 0:
        ans.append(i)
        if i != tmp // i:
            ans.append(tmp // i)

ans.append(tmp)
ans.sort()

for i in ans:
    print(i, end=" ")
