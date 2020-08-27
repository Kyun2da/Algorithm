N = int(input())

count = 0

# 큰 단위의 화폐부터 차례대로 확인
list = [500, 100, 50, 10]

for coin in list:
    count += N // coin
    N %= coin

print(count)

# 주의할 점 이때 화폐는 반드시 큰단위가 작은단위의 배수가 되어야 그리디가 성립한다.